import gspread
from oauth2client import client
from oauth2client.service_account import ServiceAccountCredentials
from fastapi import FastAPI
import fastapi
import uvicorn


app = FastAPI()

scope = ["https://spreadsheets.google.com/feeds",'https://www.googleapis.com/auth/spreadsheets',"https://www.googleapis.com/auth/drive.file","https://www.googleapis.com/auth/drive"]

creds = ServiceAccountCredentials.from_json_keyfile_name("key.json",scope)
client = gspread.authorize(creds)
sheet = client.open("RADLY").sheet1
data  = sheet.get_all_records()

@app.get("/{course}/{name}/{cls}/{num}/{email}")
def read_item(course: str,name:str,cls :str , num:str , email :str):
    return {"course": course,
            "name": name,
            "cls" : cls ,
            "num" : num,
            "email" : email,
            "check" : "สมัครเสร็จสิ้นค่ะ",

            "append":sheet.append_row([course,name,cls,num,email])}


if __name__ == "__main__":
    uvicorn.run(app)