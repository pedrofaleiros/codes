import pymysql.cursors

conexao = pymysql.connect(
    host='localhost',
    user='root',
    password='',
    db='interacaopy',
    charset='utf8mb4',
    cursorclass= pymysql.cursors.DictCursor

)

nome = input("Nome: ")
idade = input("Idade: ")
endereco = input("Endereco: ")


with conexao.cursor() as cc:
    try:
        cc.execute(f'insert into people values("{nome}", {int(idade)}, "{endereco}");')
        conexao.commit()
        print("OK!")
    except:
        print("Erro")
