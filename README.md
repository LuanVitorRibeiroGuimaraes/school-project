# 📚 Sistema de Gestão Escolar em C

Este é um projeto desenvolvido para a disciplina de *Laboratório de Programação (INF029)* do curso de Análise e Desenvolvimento de Sistemas. O objetivo foi construir um sistema em linguagem C que simula o funcionamento básico de uma escola, com foco em cadastro e gerenciamento de alunos, professores e disciplinas, além de diversos relatórios.

## ✅ Funcionalidades Implementadas

### 👨‍🎓 Cadastro de Alunos
- Matrícula
- Nome
- Sexo
- Data de Nascimento
- CPF

### 👨‍🏫 Cadastro de Professores
- Matrícula
- Nome
- Sexo
- Data de Nascimento
- CPF

### 📖 Cadastro de Disciplinas
- Nome
- Código
- Semestre
- Professor responsável
- Inserção/Remoção de alunos na disciplina

### 📊 Relatórios
- Listar todos os alunos
- Listar todos os professores
- Listar todas as disciplinas (sem os alunos)
- Listar uma disciplina (com os alunos matriculados)
- Listar alunos por sexo
- Listar alunos ordenados por nome
- Listar alunos ordenados por data de nascimento
- Listar professores por sexo
- Listar professores ordenados por nome
- Listar professores ordenados por data de nascimento
- Aniversariantes do mês (alunos e professores)
- Lista de pessoas (aluno/professor) com base em uma string de busca (mínimo 3 letras)
- Alunos matriculados em menos de 3 disciplinas
- Disciplinas que ultrapassam 40 vagas (com nome do professor)

## ⚠️ Validações
- Validação de CPF
- Validação de data de nascimento
- Outros campos obrigatórios tratados via entrada com fgets() e sscanf()

## 👥 Divisão da Equipe

| Integrante | Responsável por |
|-----------|------------------|
| *Luan*  | Módulo de Alunos, estrutura, validações |
| *Caio* | Módulo de Professores, estrutura, validações  |
| *Cleiton* | Módulo de Disciplinas, validações |


## 🛠️ Compilação

Para compilar o projeto, utilize o seguinte comando no terminal:

```bash
gcc main.c students/*.c subject/*.c teachers/*.c validators/teacher/validateTeacherId.c validators/student/validateStudentId.c validators/*.c utils/*.c -o schoolSystem