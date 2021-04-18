from __future__ import annotations

import os
from dataclasses import dataclass


@dataclass
class Music:
    author: str
    title: str
    length: float


@dataclass
class Node:
    value: Music
    before: Node = None
    after: Node = None


head = None


def add_music():
    global head

    author = input("Autor da musica: ")
    title = input("Nome da musica: ")
    length = input("Duração da musica: ")

    music = Music(author, title, length)
    node = Node(music)

    if not head:
        head = node
    else:
        prev_head = head
        prev_head.before = node
        head = node
        head.after = prev_head

    input("Musica adicionada! Pressione qualquer tecla para continuar.")


def clear_music_list():
    global head

    if not head:
        return
    
    head.before = None
    head = head.after
    
    clear_music_list()

def show_musics():
    node: Node = head

    if not node:
        return

    while True:
        os.system("clear")

        if not node.after or not node.before:
            print("Fim da lista")
        
        print(f"Autor: {node.value.author}\nNome: {node.value.title}\nDuração: {node.value.length}")

        action = input("1. Anterior\n2. Próxima\n3. Voltar\n")
        
        if not action.isdigit():
            continue
        
        action = int(action)

        if action == 1 and node.before:
            node = node.before
        if action == 2 and node.after:
            node = node.after
        if action == 3:
            break


def main():
    while True:
        print("------ MENU ------")
        print("1. Adicionar musica.\n2. Ver musicas.\n3. Limpar musicas.\n0. Sair")

        option = input()

        if not option.isdigit():
            print("Valor de entrada errado!")
            continue
        
        option = int(option)

        if option == 1:
            add_music()
        if option == 2:
            show_musics()
        if option == 3:
            clear_music_list()
        if option == 0:
            break

        os.system("clear")


if __name__ == "__main__":
    main()
