from tkinter import *
from tkinter import ttk

janela = Tk()
janela.title("Treeview")

tree = ttk.Treeview(janela, selectmode='browse', columns=('co1', 'co2', 'co3'), show='headings')

tree.column('co1', stretch=NO)
tree.heading('#1', text = 'nome')

tree.column('co2', stretch=NO)
tree.heading('#2', text = 'idade')

tree.column('co3', stretch=NO)
tree.heading('#3', text='ID')


elements = [['Pedro', 19, 1], ['Ana Luiza', 45, 2], ['Flavio', 49, 3], ['Artur', 16, 4]]

for i in range(4):
    tree.insert('', END, values=elements[i], tag='1')


tree.grid(row=0, column=0)

janela.mainloop()
