import whisper
import sys
import os

def transcrever_audio(caminho_audio, caminho_saida="transcricao.txt"):
    # Carrega o modelo base (use 'small', 'medium', 'large' para mais precisão)
    modelo = whisper.load_model("medium")

    # Transcreve o áudio
    resultado = modelo.transcribe(caminho_audio)

    # Salva a transcrição no arquivo de texto
    with open(caminho_saida, "w", encoding="utf-8") as f:
        f.write(resultado["text"])

    print(f"Transcrição salva em: {caminho_saida}")

# Exemplo de uso
if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Uso: python transcrever.py arquivo_audio.mp3")
    else:
        caminho_audio = sys.argv[1]
        if not os.path.exists(caminho_audio):
            print("Arquivo de áudio não encontrado!")
        else:
            transcrever_audio(caminho_audio)
