import customtkinter as ctk

windows = ctk.CTk()
windows.title("calc")
windows.geometry("600x500")
def delete():
    Label.destroy()
    Button.destroy()

def yes_no(task):
    delete()
    label = ctk.CTkLabel(frame,text=None,width=50,height=50)
    if task == "да":
        label.configure(text="пизда")

    elif task == "нет":
        label.configure(text="нет ты еблан")

    label.place(x=125,y=50)

button = (
    ("да",90,120,lambda:yes_no("да")),("нет",160,120,lambda:yes_no("нет"))
)

frame = ctk.CTkFrame(windows,width=300,height=300)

for btn,x,y,command in button:
    Label = ctk.CTkLabel(frame,text="ты еблан",width=50,height=50)
    Button = ctk.CTkButton(frame,text=btn,width=50,height=50,command=command)
    Label.place(x=125,y=50)
    Button.place(x=x,y=y)

frame.place(x=150,y=100)
windows.mainloop()
