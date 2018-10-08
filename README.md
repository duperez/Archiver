arquivador -c <novoarchive.arq> <arq1> <arq2> ...
Cria arquivo novoarchive.arq cujos arquivos são arq1, arq2 etc.
Exemplo:
arquivador -c eleicao2018.arq intencoes_dos_candidatos.txt discurso13.mp3 discurso17.mp3
arquivador -i <archive.arq> <arq>
Insere arquivo arq em archive.arq.
Exemplo:
arquivador -i eleicao2018.arq democracia.doc
arquivador -l <archive.arq>
Lista os nomes de arquivos que estão em archive.arq, um por linha
Exemplo:
arquivador -l eleicao2018.arq
arquivador -e <archive.arq> <arq>
Extrai arquivo arq de archive.arq, caso exista.
Exemplo:
arquivador -e eleicao2018.arq intencoes_dos_candidatos.txt
arquivador -r <archive.arq> <arq>
Remove arquivo arq de archive.arq, caso exista.
Exemplo:
arquivador -r eleicao2018.arq ditadura.doc
