import pymysql.cursors

conexao = pymysql.connect(
    host = 'localhost',
    user = 'root',
    password = '',
    db = 'interacaopy',
    charset = 'utf8mb4',
    cursorclass = pymysql.cursors.DictCursor

)

with conexao.cursor() as cc:
    cc.execute('select * from people;')
    dados = cc.fetchall()

print(dados)

for data in dados:
    print(data)

for data in dados:
    print(data['nome'])

with conexao.cursor() as cc:
    cc.execute('select nome from people;')
    dados_nome = cc.fetchall()

print(dados_nome)