from tkinter import *

def calcular():
    peso1 = float(peso.get())
    altura1 = float(altura.get())
    
    imc = peso1/altura1**2
    
    resp['text'] = imc
    
    

janela = Tk()
janela.title('Calculadora de IMC')
janela.geometry('300x300')
janela.resizable(True, True)

Label(janela, text='Insira seus dados:').grid(row=0, column=0, columnspan=2)

Label(janela, text='Peso:').grid(row=1, column=0)

peso = Entry(janela)
peso.grid(row=1, column=1)

Label(janela, text='Altura:').grid(row=2, column=0)

altura = Entry(janela, )
altura.grid(row=2, column=1)

Button(janela, text="Calcular", command=calcular).grid(row=3, column=0)

resp = Label(janela, text="Resposta")
resp.grid(row=3, column=1)

janela.mainloop()
