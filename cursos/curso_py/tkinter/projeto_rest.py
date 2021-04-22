from tkinter import *
from tkinter import messagebox
from tkinter import ttk
import pymysql

class JanelaLogin():
    
    def ConfirmaCadastro(self):
        
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
            print("erro ao conectar banco 2")
            
        achou_nome = False
        nome = self.nome.get()
        senha = self.senha.get()
        
        try:
            with conexao.cursor() as cc:
                cc.execute('select * from cadastros;')
                dados = cc.fetchall()
                
        except:
            print("erro ao acessar banco 5")
            
        for pessoa in dados:
            if nome == pessoa['nome']:
                achou_nome = True
                break
        
        if nome != '':
            if not achou_nome:
                try:
                    with conexao.cursor() as cc:
                        cc.execute('insert into cadastros (nome, senha, nivel) values(%s, %s, %s);', (nome, senha, 1))
                        conexao.commit()
                    messagebox.showinfo('', 'cadastrado')
                    self.janela.destroy()
                    JanelaLogin()
                except:
                    print("erro ao acessar dados 2")
            else:
                messagebox.showinfo('', 'nome ja existe')
        else:
            messagebox.showinfo('', 'digite seu nome')
            self.janela.destroy()
            JanelaLogin()  
             
    def FazCadastro(self):
        
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
            print("erro ao conectar banco 3")
            
        nome = self.nome.get()
        senha = self.senha.get()
        
        nome_existe = False
        
        try:
            with conexao.cursor() as cc:
                cc.execute('select * from cadastros')
                dados = cc.fetchall()
        except:
            print("erro ao acessar dados 3")
            
        for linha in dados:
            if nome == linha['nome']:
                nome_existe = True
                break
            
        if not nome_existe:
            Button(self.janela, text='Clique para confirmar cadastro', bg='yellow', command=self.ConfirmaCadastro).grid(row=2, column=0, columnspan=3)
        else:
            messagebox.showinfo('', 'nome ja existe')
    
    def VerificaLogin(self):
        logado = False
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
            print("erro ao conectar banco 1")
            
        nome_usuario = self.nome.get()
        senha_usuario = self.senha.get()
        
        try:
            with conexao.cursor() as cc:
                cc.execute('select * from cadastros')
                dados = cc.fetchall()
        except:
            print("erro ao acessar dados 1")
            
        nome_existe = False
        for pessoa in dados:
            if nome_usuario == pessoa['nome']:
                nome_existe = True
                if senha_usuario == pessoa['senha']:
                    if pessoa['nivel'] == 2:
                        adm = True
                    logado = True
                    messagebox.showinfo('', 'LOGADO')
                else:
                    messagebox.showinfo('', 'Senha errada')
                    
        if not nome_existe:
            messagebox.showinfo('', 'Nome nao encontrado')
            
        if logado:
            self.janela.destroy()
    
    def MostraCadastros(self):
        
        self.cad = Toplevel()
        self.cad.resizable(False, False)
        self.cad.title('Cadastros')
        self.cad['bg'] = '#444444'
        
        self.tree = ttk.Treeview(self.cad, selectmode='browse', columns=('c1', 'c2'), show='headings')
        
        self.tree.column('c1', stretch=NO, width=150)
        self.tree.heading('#1', text='Nome')
        
        self.tree.column('c2', stretch=NO, width=150)
        self.tree.heading('#2', text='Senha')
        
        self.tree.grid(row=0, column=0, padx=10, pady=10)
        
        self.PegaDadosTree()
        
        self.tree.mainloop()
        
    def PegaDadosTree(self):
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
            print("erro ao conectar banco 6")
            
        try:
            with conexao.cursor() as cc:
                cc.execute('select * from cadastros;')
                resultado = cc.fetchall()
        except:
            print("Erro ao acessar dados 6")
            
        self.tree.delete(*self.tree.get_children())
        
        linha = []
        
        for line in resultado:
            linha.append(line['nome'])
            linha.append(line['senha'])
            self.tree.insert('', END, values=linha)
            linha.clear()
    
    def __init__(self):
        
        self.janela = Tk()
        self.janela.title("Faça o Login")
        
        Label(self.janela, text='Nome', width=20, height=2, bg='grey10' , fg='white').grid(row=0, column=0)
        Label(self.janela, text='Senha', width=20, height=2, bg='grey12', fg='white').grid(row=1, column=0)
        
        self.nome = Entry(self.janela)
        self.nome.grid(row=0, column=1)
        
        self.senha = Entry(self.janela, show='*')
        self.senha.grid(row=1, column=1)
        
        Button(self.janela, text='cadastrar', width=20, bg='#547d94', command=self.FazCadastro , highlightbackground='#000000').grid(row=3, column=0)
        Button(self.janela, text='login'    , width=20, bg='#f4a500', command=self.VerificaLogin).grid(row=3, column=1)
        
        Button(self.janela, text='Ver Cadastros', bg='#777777', width=30, command=self.MostraCadastros).grid(row=4, column=0, columnspan=2)
        
        self.janela.mainloop()
        
JanelaLogin()