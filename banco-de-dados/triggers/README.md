# Exemplo de Triggers no PostgreSQL

Desenvolvido como trablho da disciplina de banco de dados da Universidade Tecnológica Federal do Paraná com o ojetivo de demonstrar a funcionalidade de acionamento de triggers dentro do postgres.

## Desenvolvedores

- [Daniel Gustavo Favero](https://github.com/danielg-favero)
- [Luiz Henrique Vicari](https://github.com/LuizHVicari)

## Repositório original da integração NextJS + Prisma

- [NextJS + Prisma](https://github.com/souzjfe/nextjs-form-prismajs)

## Dependências

- [Git](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git)
- [NodeJs](https://nodejs.org/en/)
- [PostgreSQL](https://www.postgresql.org/)

## Configuração inicial

Basta informar os dados necessários para conexão com PostgreSQL. Para isso no arquivo `.env` na raiz do projeto, adicione a variável:

```env
DATABASE_URL="postgresql://USERNAME_POSTGRE:SENHA_POSTGRE@localhost:PORTA?schema=public"
```

Substituindo `USERNAME_POSTGRE`, `SENHA_POSTGRE` e `PORTA` respectivamente por usuário, senha e porta já configurado em seu banco PostgreSQL.

## Como iniciar o projeto

1. Clone o repositório

```zsh
git clone https://github.com/danielg-favero/triggers-postgres
```

2. Abra a pasta clonada

```bash
cd triggers-postgres
```

3. Instalar dependências do client

```shell
yarn
```

4. Criar as tabelas do banco

```shell
npx prisma db push
```

5. Popular o banco de dados com o script encontrado em `sql/inital_data.sql`

6. Criar a trigger com o script encontrado em `sql/triggers.sql`

7. Iniciar client no navegador

```shell
yarn dev
```

Acesse [localhost:3000](http://localhost:3000/)


Enjoy!! 😊