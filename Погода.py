import customtkinter as ctk
import requests
windows = ctk.CTk()
windows.title("Погода в Москве")
windows.geometry("500x390")
windows.resizable(False,False)
def describe_weather(code):
    descriptions = {0:"Ясно",1:"Преимущественно ясно",2:"Переменная облачность",3:"Облачно",45:"Туман",48:"Изморозь и туман",51:"Лёгкая морось",53:"Морось",55:"Сильная морось",61:"Небольшой дождь",63:"Дождь",65:"Сильный дождь",71:"Небольшой снег",73:"Снег",75:"Сильный снег",80:"Ливень",81:"Сильный ливень",82:"Очень сильный ливень",95:"Гроза",96:"Гроза с градом",99:"Сильная гроза с градом",}
    return descriptions.get(code,"Переменная погода")
ctk.CTkLabel(windows,text="Погода в Москве",font=ctk.CTkFont(size=24,weight="bold"),
).pack(pady=(22,14))
try:
    response = requests.get("https://api.open-meteo.com/v1/forecast",params={"latitude":55.7558,"longitude":37.6173,"current":"temperature_2m,apparent_temperature,weather_code,wind_speed_10m"},timeout=10)
    response.raise_for_status()
    current = response.json()["current"]
    weather_items = (("Сейчас",describe_weather(current["weather_code"])),("Температура",f"{current['temperature_2m']} °C"),("Ощущается как",f"{current['apparent_temperature']} °C"),("Скорость ветра",f"{current['wind_speed_10m']} км/ч"))
    grid = ctk.CTkFrame(windows,fg_color="transparent")
    grid.pack(fill="both",expand=True,padx=20,pady=(0,20))
    grid.grid_columnconfigure((0,1),weight=1,uniform="column")
    grid.grid_rowconfigure((0,1),weight=1,uniform="row")
    for index,(title,value) in enumerate(weather_items):
        card = ctk.CTkFrame(grid,corner_radius=12)
        card.grid(row=index // 2,column=index % 2,sticky="nsew",padx=6,pady=6)
        ctk.CTkLabel(card,text=title).pack(expand=True,pady=(14,2))
        ctk.CTkLabel(card,text=value,font=ctk.CTkFont(size=20, weight="bold"),wraplength=190,).pack(expand=True, pady=(2, 14))
except (requests.RequestException,KeyError,ValueError) as error:
    ctk.CTkLabel(windows,text=f"Не удалось загрузить погоду.\nПроверь подключение к интернету.\n\n{error}",wraplength=420,).pack(expand=True, padx=24)
windows.mainloop()
