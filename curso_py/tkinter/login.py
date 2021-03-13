from tkinter import *
from tkinter import messagebox
import pymysql

class TelaLogin():
    def __init__(self):
        self.janela = Tk()
        self.janela.title('Tela de Login')
        
        Label(self.janela, text='Nome',  width=20, height=2, bg='#86bddd').grid(row=0, column=0)
        Label(self.janela, text='Senha', width=20, height=2, bg='#6479dd').grid(row=1, column=0)
        
        self.nome = Entry(self.janela, width=30)
        self.nome.grid(row=0, column=1)
        
        self.senha = Entry(self.janela, width=30, show='*')
        self.senha.grid(row=1, column=1)
        
        Button(self.janela, text='Cadastrar', bg='orange', width=20).grid(row=2, column=0)
        
        Button(self.janela, text='Login', bg='green', width=20, command=self.VerificaLogin).grid(row=2, column=1)
        
        Button(self.janela, text='Ver cadastros', bg='grey', width=20).grid(row=3, column=0, columnspan=2)
        
        self.janela.mainloop()
        
    def VerificaLogin(self):
        
        esta_logado = False
        adm = False
        
        try:
            conexao = pymysql.connect(
                host='localhost',
                user='root',
                password='',
                db='loja',
                charset='utf8mb4',
                cursorclass = pymysql.cursors.DictCursor
            )
            
        except:
            print('erro ao conectar bdd')
        
        nome_usuario = self.nome.get()
        senha_usuario = self.senha.get()
        
        try:
            with conexao.cursor() as cc:
                cc.execute('select * from cadastros')
                resultado = cc.fetchall()
        except:
            print('erro na consulta sql')
            
        for linha in resultado:
            if nome_usuario == linha['nome']:
                if senha_usuario == linha['senha']:
                    if linha['nivel'] == 2:
                        adm = True
                    else:
                        adm = False
                    esta_logado = True
                    break
                else:
                    print("Senha errada")
                    
        if not esta_logado:
            messagebox.showinfo('login', 'Erro ao fazer login')
        else:
            self.janela.destroy()
            if adm:
                messagebox.showinfo('login', 'autenticado adm')
            else:
                messagebox.showinfo('login', 'autenticado')
                
         
TelaLogin()