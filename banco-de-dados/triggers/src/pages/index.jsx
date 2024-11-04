import { useEffect, useState } from "react";
import { useForm } from "react-hook-form";
import { yupResolver } from "@hookform/resolvers/yup";
import * as Yup from "yup";

import prisma from "../lib/prisma";
import { convertDate } from '../utils/convertDate'

export default function Home({ nacionalidades, estados_civis }) {
  const [pessoas, setPessoas] = useState([]);
  const [isLoadingInsert, setIsLoadingInsert] = useState(false);
  const [isLoadingDelete, setIsLoadingDelete] = useState(false);

  async function loadUsers()   {
    try{
      await fetch(`/api/person`, { method: "GET" })
      .then(res => res.json())
      .then(data => { setPessoas(data) });
    } catch (error) { 
      alert("ERRO AO CARREGAR OS USUÁRIOS");
    }
  }

  useEffect(() => {
    loadUsers();
  }, [])

  const validationSchema = Yup.object().shape({
    nomePessoa: Yup.string().required("Nome é obrigatório"),
    sobrenomePessoa: Yup.string().required("Sobrenome é obrigatório"),
    dataNascimento: Yup.string()
    .required("Data de nascimento é obrigatória")
    .matches(
      /^\d{4}-(0[1-9]|1[012])-(0[1-9]|[12][0-9]|3[01])$/,
      "Data de nascimento deve ser no formato YYYY-MM-DD"
      ),
    nacionalidade: Yup.string().required("Nacionalidade é obrigatório"),
    est_civil: Yup.string().required("Estado Civil é obrigatório"),
  });
  const formOptions = { resolver: yupResolver(validationSchema) };

  // get functions to build form with useForm() hook
  const { register, handleSubmit, reset, formState } = useForm(formOptions);
  const { errors } = formState;

  async function onSubmit(data) {
    const body = JSON.stringify({
      nome: data.nomePessoa,
      sobrenome: data.sobrenomePessoa,
      nasc: new Date(data.dataNascimento),
      fk_nacionalidade: parseInt(data.nacionalidade),
      fk_estado_civil: parseInt(data.est_civil)
    });
    
    setIsLoadingInsert(true);
    try {
      await fetch(`/api/person`, {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body,
      }).then(res => {
        loadUsers();
      })
    } catch (error) {
      alert(error);
    } finally {
      setIsLoadingInsert(false);
    }
    return false;
  }

  async function deleteAllUsers() {
    setIsLoadingDelete(true);
    try {
      await fetch(`/api/person`, {
        method: "DELETE",
      }).then(res => {
        loadUsers();
      });
    } catch (error) {
      alert(error);
    } finally {
      setIsLoadingDelete(false);
    }
    return false;
  }

  if (pessoas === []) return "Carregando..."
  return (
    <>
      <div className="card m-3">
        <h5 className="card-header">
          Formulário exemplo para exemplificar Triggers no PostgreSQL
        </h5>
        <div className="card-body">
          <form onSubmit={handleSubmit(onSubmit)}>
            <div className="form-row">
              <div className="form-group col">
                <label>Nome</label>
                <input
                  name="nomePessoa"
                  type="text"
                  {...register("nomePessoa")}
                  className={`form-control ${
                    errors.nomePessoa ? "is-invalid" : ""
                  }`}
                />
                <div className="invalid-feedback">
                  {errors.nomePessoa?.message}
                </div>
              </div>
              <div className="form-group col">
                <label>Sobrenome</label>
                <input
                  name="sobrenomePessoa"
                  type="text"
                  {...register("sobrenomePessoa")}
                  className={`form-control ${
                    errors.sobrenomePessoa ? "is-invalid" : ""
                  }`}
                />
                <div className="invalid-feedback">
                  {errors.sobrenomePessoa?.message}
                </div>
              </div>
            </div>
            <div className="form-row">
              <div className="form-group col">
                <label>Data de nascimento</label>
                <input
                  name="dataNascimento"
                  type="date"
                  {...register("dataNascimento")}
                  className={`form-control ${
                    errors.dataNascimento ? "is-invalid" : ""
                  }`}
                />
                <div className="invalid-feedback">
                  {errors.dataNascimento?.message}
                </div>
              </div>
            </div>
            <div className="form row">
                <div className="form-group col">
                  <label>Nacionalidade</label>
                  <select
                    name="nacionalidade"
                    {...register("nacionalidade")}
                    className={`form-control ${errors.nacionalidade ? "is-invalid" : ""}`}
                  >
                    <option value="" hidden>
                      Selecione sua nacionalidade
                    </option>
                    {nacionalidades.map((nacionalidade) => (
                      <option  key={nacionalidade.pk_nacionalidade} value={nacionalidade.pk_nacionalidade}>{nacionalidade.pais}</option>
                    ))}
                  </select>
                  <div className="invalid-feedback">{errors.nacionalidade?.message}</div>
                </div>
              </div>
            <div className="form row">
                <div className="form-group col">
                  <label>Estado Civil</label>
                  <select
                    name="est_civil"
                    {...register("est_civil")}
                    className={`form-control ${errors.est_civil ? "is-invalid" : ""}`}
                  >
                    <option value="" hidden>
                      Selecione um estado civil
                    </option>
                    {estados_civis.map((estados_civil) => (
                      <option key={estados_civil.pk_estado_civil} value={estados_civil.pk_estado_civil}>{estados_civil.est_civil}</option>
                    ))}
                  </select>
                  <div className="invalid-feedback">{errors.est_civil?.message}</div>
                </div>
              </div>
            <div className="form-group form-check">
              <div className="invalid-feedback">
                {errors.acceptTerms?.message}
              </div>
            </div>
            <div className="form-group">
              <button type="submit" className="btn btn-primary mr-1">
                {
                  isLoadingInsert ?
                  <div className="spinner-border spinner-border-sm text-light" role="status">
                    <span className="visually-hidden"></span>
                  </div> :
                  'Cadastrar'
                }
              </button>
              <button
                type="reset"
                onClick={() => reset()}
                className="btn btn-secondary"
              >
                Limpar
              </button>
            </div>
          </form>
        </div>
      </div>
      <div className="card m-3">
        <h5 className="card-header">
          Usuários cadastrados
        </h5>
        <div className="card-body">
              {pessoas !== [] && pessoas.map(pessoa => (
                <div className="card-m4">
                  <h5 className="card-header">{pessoa.nome + ' ' + pessoa.sobrenome}</h5>
                  <div className="card-body">
                    <h6 className="text-muted">
                      <b>Data de nascimento: </b>
                      {convertDate(new Date(pessoa.nasc))}
                    </h6>
                    <h6 className="text-muted">
                      <b>Nacionalidade: </b>
                      {nacionalidades[pessoa.fk_nacionalidade - 1].pais}
                    </h6>
                    <h6 className="text-muted">
                      <b>Estado civil: </b>
                      {estados_civis[pessoa.fk_estado_civil - 1].est_civil}
                    </h6>
                  </div>
                </div>
              ))}
              <button
                type="reset"
                onClick={() => deleteAllUsers()}
                className="btn btn-danger"
              >
                {
                  isLoadingDelete ?
                  <div className="spinner-border spinner-border-sm text-light" role="status">
                    <span className="visually-hidden"></span>
                  </div> :
                  'Excluir todos os dados'
                }
              </button>
        </div>
      </div>
    </>
  );
}

export const getStaticProps = async () => {
  const pessoas = await prisma.Pessoa.findMany();
  const nacionalidades = await prisma.Nacionalidade.findMany();
  const estados_civis = await prisma.EstadoCivil.findMany();

  return {
    props: { 
      pessoas: JSON.parse(JSON.stringify(pessoas)),
      nacionalidades,
      estados_civis
    },
    revalidate: 20
  };
};