import gspread
from oauth2client import client
from oauth2client.service_account import ServiceAccountCredentials
from fastapi import FastAPI
import fastapi



app = FastAPI()

scope = ["https://spreadsheets.google.com/feeds",'https://www.googleapis.com/auth/spreadsheets',"https://www.googleapis.com/auth/drive.file","https://www.googleapis.com/auth/drive"]

creds = ServiceAccountCredentials.from_json_keyfile_name({
  "type": "service_account",
  "project_id": "radly-346009",
  "private_key_id": "d3769eea5717461c45e99adef0c89ea0d80ec56d",
  "private_key": "-----BEGIN PRIVATE KEY-----\nMIIEvwIBADANBgkqhkiG9w0BAQEFAASCBKkwggSlAgEAAoIBAQC7ZAeDcEa2J5+0\nXYQxlUZF8CKYIUhvH7I/PQzsZku7wJe0Yw+GJs3Fac2e9K5H9c8uGpfpeKcPBIN9\n0wy7NeHAPf951X8hb+oJfX4qQM2/PC72MqTXrjYPbO4lvkBHMu3cYHbvAsekqp36\nZZwOQzrYzQPBEibiESdIFHVggin3+y+drrfmpp2ZA4RKk15/0RcvsFZ0Asjdj/F0\nAdYsivqqcJcCgs6YLCwASewLpeVwFN1QMKdUtxlDECQ/F3WZUehxo8k4Pbp4aPuy\nzVSlBrRu1GjnCQHsN9MFOrvv0P6OeuGbe4Cib9u5nZyVf/Ct1i7bvw8/hE3frHj/\nC9BwHQf9AgMBAAECggEAEXzQRq/fqXghK0/e2lG38Sbr046nl9c5ZzVnU1hokOj0\nP11PQZG1ekrZaZAkA4so/oB01NDxpjEhpEhh08a/fpVKljAaYSB0ktYnRAIwMTyI\nlWk8gPQ9D0t3HgaXMQ3LrNlDwCJeRzu06n05Bwu3HixjwUzUXByFsfBW097R09Zv\n7o2kotl1HOODmz0gys9Y6eXTn8p9EBJAXb5Nyz9wTFgw+giNKFqOZ9LMpoSGMhq9\nm9t/aOUpppoWwLOIpIXKI3M41NtxvzUSfXcLNyJ2UIQc0zhPuUkah40J8JfxOkk5\nbY1J8EuooHMnShJM+9FhHMv/t6NUeTZB3891i9/+gQKBgQD5MwiZkBdqSpdYuBZP\nJfk1Ka1+f4qQL6Dr+eyCa8E6FxBeNa54xtX5Muyc3n8tUoy+ytyZmKrQTT8SzpMW\n8ls9cVocpm0cALaDNAT3Jc+TNeWm2a11F30YIRail9C4YV9s47OkAzT7JMsLoakt\n7Xc3/c0mrQuzCmgUeNs+b+LziQKBgQDAgS+cuheoPdIdObhUKsoqTQ3UieVZjlFz\npVX5cYrRU+ZHGx9gqar4RQa6cZSwzkxb29fZ+3rZdj8DQjX01ZMadRjF2SDgUul7\n57JnSLsA84PhuW2CYixBT1BnzMnIgrqGryDJzbVlrvNksyT9bjtDSo9wNJU7CmU/\nRKs9TzBv1QKBgQDcypyqAoLciC5ESwZpJgoBUmYHmFVanviDW7Jzc6mGIH0+G230\nUKew3a/K5U/lBijxuqdt51ggqvBhZ2nngN/aNp5SmBpAH1mWMfbcS0H4+l35URBg\nmGkbgeWeNciWNJ/pyG2XucetZNIKAjf1G1rv3w1vYQ7mmSfSS6plTZjVkQKBgQC6\nCh9hb9b9GQG+jNG/RbsrNlxvUvT7n7bH9Lkp4Lkvo82gWm3wlQhN9yeRd8MjO7w/\n6i6o04jeMJClLY/HlcAciZ3vVu+W24oZ3MllV7yiJrUFqJZUs1vhoi0qo5c+2Fg7\nYXRmkw8Dvhgq8ZaF9coANkZ5QdgWvu0qP8rd7XH6IQKBgQDnIwo0S3W81F00RTLS\n+JZFUK90Be65PYiW+yhkWDTB2exgW2vOSgwROv4q/TFHBX3B8mtV5dKPEeV2+XNE\nBmzvqXxyB2bzhPUy+ZARdHTlxTZZpcqMgPawVD0VkfWy1KZZ2Z+cdUz/8Q4RyP8Z\nIp/3pqK3m4Y1YHsjZlxoPbf/aQ==\n-----END PRIVATE KEY-----\n",
  "client_email": "pythonapi@radly-346009.iam.gserviceaccount.com",
  "client_id": "112999262655934969084",
  "auth_uri": "https://accounts.google.com/o/oauth2/auth",
  "token_uri": "https://oauth2.googleapis.com/token",
  "auth_provider_x509_cert_url": "https://www.googleapis.com/oauth2/v1/certs",
  "client_x509_cert_url": "https://www.googleapis.com/robot/v1/metadata/x509/pythonapi%40radly-346009.iam.gserviceaccount.com"
}
,scope)
client = gspread.authorize(creds)
sheet = client.open("RADLY").sheet1
data  = sheet.get_all_records()

@app.get("/{course}/{name}/{cls}/{num}/{email}/")
def read_item(course: str,name:str,cls :str , num:str , email :str):
    return {"course": course,
            "name": name,
            "cls" : cls ,
            "num" : num,
            "email" : email,
            "check" : "สมัครเสร็จสิ้นค่ะ",

            "append":sheet.append_row([course,name,cls,num,email])}




