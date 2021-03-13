import pymysql.cursors

conexao = pymysql.connect(
    host = 'localhost',
    user = 'root',
    password = '',
    db = 'interacaopy',
    charset = 'utf8mb4',
    cursorclass = pymysql.cursors.DictCursor

)

cc = conexao.cursor()

cc.execute("""create table people(
    nome varchar(50) primary key,
    idade int,
    endereco varchar(100)
);""")

cc.close()
conexao.close()