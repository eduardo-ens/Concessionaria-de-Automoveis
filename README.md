# Concessionaria-de-Automoveis

2º Trabalho Prático – Concessionária de Automóveis

Implemente uma aplicação em C para o controle de vendas em uma concessionária de automóveis. 

Um automóvel possui as seguintes características: código, marca, modelo, ano, preço e umcampo que indica se ela já foi vendido ou não. 

Um vendedor possui os seguintes dados: código e nome. 

Quando um automóvel é vendido, guarda-se as informações da data da venda, código doautomóvel e código do vendedor. O valor da venda é sempre igual ao preço do automóvel.

O sistema deve possuir as seguintes funcionalidades:

a) Cadastrar automóvel: o sistema deve gerar o código do automóvel de forma automática esequencial e solicitar sua marca, modelo, ano e preço. Todo automóvel que é cadastrado aprincípio ainda não foi vendido. Os automóveis cadastrados devem ser armazenados numarquivo cujo nome é definido pela constante  ARQ_AUTOMOVEIS  declarada no arquivoautomovel.h (vide adiante);

b) Alterar automóvel: o sistema deve solicitar o código do automóvel, mostrar seus dadosatuais e permitir alterar sua marca, modelo, ano e preço. Se o código do automóvel forinválido, o sistema deve exibir uma mensagem;

c) Listar todos os automóveis: o sistema deve gerar uma listagem no formato de tabelacontendo o código, marca, modelo e preço de todos os automóveis cadastrados, tenham elessido vendidos ou não;

d) Listar os automóveis a venda: idêntica a listagem anterior, só que aparecem apenas osveículos que não foram vendidos ainda. O usuário deve ter a opção de gerar essa listagemem um arquivo do tipo texto cujo nome é definido pela constante ARQ_A_VENDA declaradano arquivo automovel.h (vide adiante);

e) Cadastrar vendedor: o sistema deve gerar o código do vendedor de forma automática esequencial e depois solicitar seu nome. Os vendedores cadastrados devem ser armazenadosem um arquivo cujo nome é definido pela constante  ARQ_VENDEDORES  declarada noarquivo vendedor.h (vide adiante);

f) Alterar vendedor: o sistema deve solicitar o código do vendedor, mostrar seu nome atual epermitir alterar seu nome. Se o código do vendedor for inválido, o sistema deve exibir umamensagem;

g) Listar vendedores: o sistema deve gerar uma listagem no formato de tabela de todos osvendedores cadastrados;

h) Cadastrar venda: o sistema deve solicitar o código do automóvel vendido, mostrar osdados desse automóvel (marca, modelo, ano e preço), e se ele ainda não foi vendido,solicitar o código do vendedor e mostrar seu nome, e solicitar a data da venda. O sistema deve mostrar mensagens adequadas se o veículo já foi vendido ou quando o código doautomóvel ou do vendedor forem inválidos. As vendas devem ser armazenadas em umarquivo cujo nome é definido pela constante ARQ_VENDAS declarada no arquivo venda.h(vide adiante);

i) Listar todas as vendas realizadas em um mês/ano: o sistema deve solicitar um mês e anoe depois gerar uma listagem em formato de tabela contendo a data da venda, marca, modelo,ano e preço do automóvel e nome do vendedor de todas as vendas neste mês/ano. No final, osistema deve exibir o valor total das vendas nesse mês/ano;

j) Listar todos os automóveis vendidos por um vendedor: o sistema deve solicitar o códigodo vendedor, mostrar seu nome, e exibir uma listagem no formato de tabela contendo a datada venda, marca, modelo, ano e preço de todos os automóveis vendidos pelo vendedor. Nofinal, o sistema deve exibir o valor total das vendas do vendedor. Se o código do vendedorfor inválido, o sistema deve exibir uma mensagem.
