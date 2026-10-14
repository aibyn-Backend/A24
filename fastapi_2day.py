from fastapi import FastAPI
from pydantic import BaseModel,Field

app = FastAPI()

class Player(BaseModel):
    name:str = Field(min_length=3,max_length=20)
    level:int = Field(ge=1,le=100)
    wins:int = Field(ge=0)

@app.post("/players")
async def create_player(player:Player):
    return {"message":"Игрок создан","player":player}
