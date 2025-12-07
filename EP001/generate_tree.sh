#!/bin/bash

# Diretório a ser examinado (padrão para o diretório atual)
DIR=${1:-.}

# Arquivo de saída Markdown
OUTPUT_FILE="tree_output.md"

# Gera o cabeçalho do Markdown
echo "# Estrutura de Diretórios" > "$OUTPUT_FILE"
echo "" >> "$OUTPUT_FILE"
echo "Abaixo está a estrutura de diretórios de '$DIR':" >> "$OUTPUT_FILE"
echo "" >> "$OUTPUT_FILE"

# Executa o comando tree e redireciona a saída para o arquivo Markdown
# O comando tree pode ser configurado para gerar uma saída limpa, sem cores e com apenas arquivos e diretórios
tree -L 2 --noreport "$DIR" >> "$OUTPUT_FILE"

# Mensagem de sucesso
echo "Estrutura de diretórios salva em '$OUTPUT_FILE'."
