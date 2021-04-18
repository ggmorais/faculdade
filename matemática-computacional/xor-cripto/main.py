# Função pra encontrar o binaro refêrente ao código ascii informado
def encontrar_binario(l_ascii, n_usados=[]):
    # Numeros por posição binaria utilizados
    numeros = [128, 64, 32, 16, 8, 4, 2, 1]
    # Váriavel para guardar o proximo numero mais proximo ao necessário
    melhor_numero = 1000

    # Itera por cada numero
    for i in range(len(numeros)):
        # Se o numero não foi utilizado e o numero é menor do que o código ascii
        if numeros[i] not in n_usados and numeros[i] < l_ascii and numeros[i] + sum(n_usados) <= l_ascii:
            # Código ascii menos numero da posição binaria
            restante = l_ascii - numeros[i]
            if restante < melhor_numero:
                melhor_numero = restante
                n_usados.append(numeros[i])

    # Se a soma dos numeros por posição binaria NÃO for igual ao código ascii
    # chama a função novamente informando os numeros utilizados e atualizados
    if sum(n_usados) != l_ascii:
        n_usados = encontrar_binario(l_ascii, n_usados)
        return n_usados
    else:
    # Se a soma dos numeros por posição binaria for igual ao código ascii, retorna uma
    # lista com com os binarios devidamente convertidos em ordem
        return [1 if v_binario in n_usados else 0 for v_binario in numeros]

def encontrar_ascii(binario):
    # Converte um código binario para um código ascii
    numeros = [128, 64, 32, 16, 8, 4, 2, 1]
    # Numero final
    final = 0
    
    # Encontra e soma cada um dos numeros por posição binaria, resultando no valor do ascii
    for i in range(len(binario)):
        if binario[i] == 1:
            final += numeros[i]  
    return final

# Converter lista de inteiros para str
def lista_int_para_str(lista):
    return ''.join([str(n) for n in lista])

# Função de encripação, recebe um texto para encriptar e a chave a ser utilizada
def cifrar(texto, chave):
    # Valores finais
    cifra_ascii, cifra_binario = '', ''
    
    # Valores binarios
    letra_binarios, chave_binarios = '', ''

    # Percorre cada caractere do texto
    for i in range(len(texto)):
        # Converte para ascii e encontra o binario do texto e chave
        binario_letra = encontrar_binario(ord(texto[i]), [])
        binario_chave = encontrar_binario(ord(chave[i]), [])

        letra_binarios += lista_int_para_str(binario_letra) + ' '
        chave_binarios += lista_int_para_str(binario_chave) + ' '

        # Cifra em binario refêrente ao caractere atual
        cifra = []

        # Loop por cada digito da sequência binaria
        for j in range(len(binario_letra)):
            # Operação lógica XOR
            # Se o digito binario do texto é igual ao da chave (1 == 1 | 0 == 0) retorna 0, se não 1
            if binario_letra[j] == binario_chave[j]:
                cifra.append(0)
            else:
                cifra.append(1) 

        # Concatena os códigos binarios
        cifra_binario += lista_int_para_str(cifra) + ' '
        
        # Converte de ascii para char e concatena para formar uma palavra final
        cifra_ascii += chr(encontrar_ascii(cifra))

    print('\nXOR binario: ')
    print('Palavra: ', letra_binarios)
    print('Chave:   ', chave_binarios)
    print('Cifra:   ', cifra_binario)

    # Retorna o TEXTO cifrado final
    return cifra_ascii

# Entradas do usuário
texto = input('Palavra a ser cifrada/decifrada: ')
chave = input('Chave a ser utilizada: ')

# Exibe o TEXTO cifrado
print('\nResultado: ', cifrar(texto, chave))
