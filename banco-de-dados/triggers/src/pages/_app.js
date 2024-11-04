import Head from 'next/head';

export default App;

function App({ Component, pageProps }) {
    return (
        <>
            <Head>
                <title>Triggers no Postgres</title>

                {/* eslint-disable-next-line @next/next/no-css-tags */}
                <link href="//netdna.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css" rel="stylesheet" />
            </Head>

            <Component {...pageProps} />

            {/* credits */}
            <div className="text-center mt-4">
                <p>
                    <a href="https://jasonwatmore.com/post/2021/09/03/next-js-form-validation-example-with-react-hook-form" target="_blank">Next.js - Formulário de exemplo utilizado</a>
                </p>
                <p>
                    <a href="https://vercel.com/guides/nextjs-prisma-postgres" target="_blank">Integração Nextjs com PrismaJs</a>
                </p>
                <p>
                    <a href="https://www.prisma.io/" target="_blank">PrismaJs</a>
                </p>
                <p>
                    <a href="https://github.com/souzjfe/nextjs-form-prismajs" target="_blank">Repositório original da interface</a>
                </p>
            </div>
        </>
    );
}
