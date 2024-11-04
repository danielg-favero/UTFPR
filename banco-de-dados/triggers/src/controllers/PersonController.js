import prisma from '../lib/prisma'


class PersonController {
  async show(req, res) {
    const pessoas = await prisma.Pessoa.findMany();
    
    return res.json(pessoas);
  }

  async create(req, res) {
    const pessoa = await prisma.Pessoa.create({ data: req.body })

    return res.json(pessoa)
  }

  async delete(req, res) {
    const deletedPessoas = await prisma.Pessoa.deleteMany();

    return res.json(deletedPessoas);
  }

}

export default new PersonController()