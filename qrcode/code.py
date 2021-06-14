import pyqrcode
import os
from django.http import HttpResponse
from django.views.decorators.csrf import csrf_exempt
import json
import hashlib
import boto3
def doesFileExist(filename,bucket):
    s3 = boto3.resource('s3')
    try:
       s3.Object(bucket,filename).load()
    except:
       return False
    return True
def uploadFile(filename,bucket,object_name):
    if object_name is None:
       object_name = filename
    if not doesFileExist(filename,bucket):
        s3 = boto3.client('s3')
        response = s3.upload_file(filename,bucket,object_name)
        return True   
    return False
@csrf_exempt
def saveqr(request):
    if request.method == "POST":
          body_unicode=request.body.decode("utf-8")
          bucket,val = body_unicode.split("=")
          url = pyqrcode.create(val)
          url_name = hashlib.md5(body_unicode.encode("ascii")).hexdigest() +".svg"
          url.svg(url_name,scale=8)
          if bucket == "":
             bucket = "qrcodes-aoantov"
          if not uploadFile(url_name,bucket,None):
             os.remove(url_name) 
             return HttpResponse(status=500)
          os.remove(url_name)
          return HttpResponse(status=200)
    return HttpResponse(status=403)
       
