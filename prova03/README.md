# Diary program
- Projeto de um  diario virtual com algumas funcionalidades listadas abaixo:

# Uso:
 - ./diary add 'mensagem' ou ./diary add
    *Escreva sua mensagem e será salva em um arquivo*

 - ./diary list
    *Irá listar todas as mensagens contida no arquivo*

 - ./diary search 'palavra' ou ./diary search
    *Busca no diary uma palavra da sua escolha*

 - ./diary interactive 
    *Cria no console um menu interativo com as funcionalidade do Diary program*

# Configurações
 - Ao executar pela primeira vez o programa irá criar um arquivo .config onde é possivel editar

    -Edite path='local/diário'
        *O programa agora carregarar de local/diário*

    -Edite default_format='%t%m%d'
        *O programa irá formatar o list para '%t%m%d'*
        *%t = hora da mensagem, %d = data da mensagem, %m = conteudo da mensagem;* 
    -Aproveite-se da edição para seu uso pessoal;  