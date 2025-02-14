<img width=100% src="https://capsule-render.vercel.app/api?type=waving&color=00bfbf&height=120&section=header"/>
<h1 align="center"><img align="center" style="border-radius: 100%;" src="https://github.com/user-attachments/assets/d96d3f73-4cff-4f9f-9feb-cf8a7ccfd9d3" width="300px;" alt=""><br>PWM BitDogLab</h1>

<h3 align="center">
  PWM na placa BitDogLab em Linguagem C
</h3>

---

Tabela de conteúdos
=================
<!--ts-->
   * [Sobre o projeto](#-sobre-o-projeto)
   * [Layout Repositorio Github](#-layout-repositorio-github)
   * [Funcionalidades](#-Funcionalidades)
   * [Como executar o projeto](#-como-executar-o-projeto)
   * [Imagens do Projeto](#-imagens-do-projeto)
     * [Imagem](#-projeto-na-extensão-wokwi-simulator-no-visual-studio)
   * [Tecnologias](#-tecnologias)
     * [Websites](#-websites)
     * [Utilitários](#user-content-server--nodejs----typescript)
   * [Contribuidores](#-contribuidores)
   * [Licença](#-licença)
<!--te-->

---

## 💻 Sobre o projeto

Este projeto implementa o controle de um **servomotor** utilizando **PWM (Pulse Width Modulation)** com o microcontrolador **RP2040** da placa **BitDogLab (Raspberry Pi Pico W)**. A simulação é feita no **Wokwi**.

### 🎯 Objetivos:
- Definir a **frequência do PWM** em **50Hz (período de 20ms)**.
- Controlar o **ângulo da flange do servomotor** ajustando o **ciclo de trabalho do PWM**:
  - **180°** → Duty Cycle: **2.400µs (0,12%)**, manter por **5s**.
  - **90°** → Duty Cycle: **1.470µs (0,0735%)**, manter por **5s**.
  - **0°** → Duty Cycle: **500µs (0,025%)**, manter por **5s**.
- Criar uma rotina para movimentação suave entre **0° e 180°**, alterando o **ciclo ativo em ±5µs** com um atraso de **10ms**.

### 🔧 Componentes Utilizados:
- **Microcontrolador:** Raspberry Pi Pico W
- **Servomotor:** Micro Servo (Simulador Wokwi)
- **GPIO Utilizada:** **GPIO 22** (Saída PWM)


## 🎨 Layout Repositorio Github
<i>
EmbarcaTech_U4_PWM

   - assets/&emsp;&emsp;&emsp;&emsp;# Midias do Projeto
       - diagrama.png
       - Video_Demonstration

   - CMakeLists.txt
   
   - diagram.json&emsp;&emsp;&emsp;&emsp;# Arquivo Wokwi do BitDogLab
   
   - main.c&emsp;&emsp;&emsp;&emsp; # Código principal do projeto
   
   - pico_sdk_import.cmake
   
   - wokwi.toml


</i>

---

## ⚙️ Funcionalidades

- Controle de Ângulo do Servomotor
- Configuração da frequência do PWM para 50Hz.
- Ajuste do duty cycle para posicionamento do servomotor em 0°, 90° e 180°.
- Movimentação periódica suave entre 0° e 180°.

---

## 🚀 Como executar o projeto

💡Siga as instruções abaixo para configurar, compilar e executar o programa.

### Pré-requisitos

Antes de começar, você vai precisar ter instalado em sua máquina as seguintes ferramentas:
  - Sistema operacional Linux, macOS ou Windows (com suporte a Makefile).
  - [Git](https://git-scm.com) (Opcional, mas recomendado),
  - [GCC compilador](https://gcc.gnu.org)
  - [Biblioteca Pico-Sdk](https://github.com/raspberrypi/pico-sdk.git) (OBS: Necessário caso queira modificar o projeto)

Além disto é bom ter um editor para trabalhar com o código como [VSCode](https://code.visualstudio.com/) com a extensão [Raspberry](https://marketplace.visualstudio.com/items?itemName=raspberry-pi.raspberry-pi-pico)  e usar o simulador web [Wokwi](https://wokwi.com) (ou a extensão do Vscode [Wokwi Simulator](https://marketplace.visualstudio.com/items?itemName=Wokwi.wokwi-vscode))

### 🎲 Dowload do Projeto

#### Dowload do Projeto no Desktop
- Opção 1:
  - Abra o terminal de comando Git Bash 
  - Clone o repositório do GitHub com o comando:
```
$ git clone https://github.com/Dyeorn/EmbarcaTech_U4_PWM
```
- Opção 2:
  - No repósitorio [EmbarcaTech_U4_PWM](https://github.com/Dyeorn/EmbarcaTech_U4_PWM) aperte o Botão <i><>code</i>
  - Aperte a opção <i>Dowload ZIP</i>


### 🎲 Rodando a Animação no Wokwi

#### Wokwi Web
- Entre no navegador e digite [Wokwi.com]()
- Faça Upload dos Arquivos <i>diagram.json</i>
- Faça upload do aquivo main <i>main.c</i> e da pasta <i>src/</i>

#### Extensão Wokwi
- Abra o Visual Studio
- Na aba da extensão [Raspberry Pi Pico](https://marketplace.visualstudio.com/items?itemName=raspberry-pi.raspberry-pi-pico), aperte para Importar o projeto
- Compile o projeto
- crie um arquivo (caso não tenha no projeto) <i>wokwi.toml</i> e digite o código:
```
[wokwi]
version = 1
firmware = 'build/main.hex'
elf = 'build/main.elf'
```
- Abra o arquivo <i>diagram.json</i>


### 🎲 Rodando as Animações na placa BitdogLab

#### Placa BitDogLab
- Através de um cabo USB conecte a placa ao seu Disposito
- Aperte o Botão Bootsel e Reset 

#### VsCode Studio
- Abra o Visual Studio
- Na aba da extensão [Raspberry Pi Pico](https://marketplace.visualstudio.com/items?itemName=raspberry-pi.raspberry-pi-pico), aperte para Importar o projeto
- Compile o projeto
- Entre na pasta <i>build/</i>
- Cole o arquivo <i>main.uf2</i> no armazenamento placa BitDog
- Ou, apenas compile o projeto e clique em "Run Project (USB)
<br>

---

## 🎥 Imagens do Projeto

### 💿 Diagrama Visual do Projeto

<p align="center"><img width="700" height="400" src="assets/Diagrama.png"></p>

Link para o video no youtube: 

---

## 🛠 Tecnologias

As seguintes ferramentas foram usadas na construção do projeto:

#### **Websites**
-   **[Github](https://github.com)**
-   **[Wokwi Web](https://gcc.gnu.org)**


#### **Utilitários**

-   Editor:  **[Visual Studio Code](https://code.visualstudio.com/)**  → Extensions:  **[C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools), [C/C++ Compile Run](https://marketplace.visualstudio.com/items?itemName=danielpinto8zz6.c-cpp-compile-run), [Raspberry Pi Pico](https://marketplace.visualstudio.com/items?itemName=raspberry-pi.raspberry-pi-pico) e [Wokwi Simulator](https://marketplace.visualstudio.com/items?itemName=Wokwi.wokwi-vscode)**

### **Versionamento**
-   **[Git](https://git-scm.com)**


---

## 👨‍💻 Contribuidores

- João Pedro Jacó Leite
- Mentor: MANOEL MESSIAS DA SILVA JUNIOR

<table>
  <tr>
    <td align="center"><img style="border-radius: 50%;" src="https://avatars.githubusercontent.com/u/112970376?v=4" width="100px;"/><br/><a href="https://github.com/Dyeorn">João Pedro Jacó<a/><br/><br/><a title="Integrante">🌐</a></td>
  </tr>
</table>
      
---

<img width=100% src="https://capsule-render.vercel.app/api?type=waving&color=00bfbf&height=120&section=footer"/>

