from tkinter import *

wind = Tk()
wind.title("Calculadora de Medias")
wind.geometry('300x300')
wind.resizable(True, True)


def calcula_media():
    media_final = (float(media1.get())+float(media2.get()))/2
    resultado['text'] = media_final
    


Label(wind, text='Media 1:', bg='#86bddd').grid(row=0, column=0)
Label(wind, text='Media 2:', bg='#5c92b2').grid(row=1, column=0)

media1 = Entry(wind)
media1.grid(row=0, column=1)
media2 = Entry(wind)
media2.grid(row=1, column=1)

Button(wind, text='Calcular', command=calcula_media).grid(row=2, column=0)
resultado = Label(wind, text='')
resultado.grid(row=2, column=1)



wind.mainloop()