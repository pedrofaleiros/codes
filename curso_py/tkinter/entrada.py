from tkinter import *

def mostrar():
    print("Hello World!")
    
def teste():
    aux['text'] = 'botao foi clicado'

janela = Tk()
janela.title('Teste')
janela.geometry('300x300')
janela.resizable(False, False)

Entry(janela, bg='orange', fg='black', show='*').grid(row=0, column=0)

Button(janela, text='clique aqui', bg='black', fg='white', height=1, command=teste).grid(row=0, column=1)

aux = Label(janela, text='Nao clicou')

aux.grid(row=1, column=1)


janela.mainloop()

