import whisper
import sys
import os

import warnings
warnings.filterwarnings("ignore", message="FP16 is not supported on CPU; using FP32 instead")

# 'tiny' 'base' 'small', 'medium', 'large'
model_name = "medium"

def transcribe_audio_seg(audio_file):

    print('> Carregando modelo...')
    model = whisper.load_model(model_name)

    print('> Transcrevendo...')
    result = model.transcribe(
        audio_file, 
        language="pt", 
        temperature=0, 
        # verbose=True,
        # initial_prompt="Este é um episódio do desenho Os Simpsons."
        )

    print('> Salvando...')
    base_name = os.path.splitext(os.path.basename(audio_file))[0]
    output_dir = "./transcription"
    os.makedirs(output_dir, exist_ok=True)
    text_file = os.path.join(output_dir, f"{base_name}.txt")

    with open(text_file, "w", encoding="utf-8") as f:
        for segment in result["segments"]:
            f.write(segment["text"].strip() + "\n")

    print(f"> Salvo em: {text_file}")

if __name__ == "__main__":
    # if len(sys.argv) < 2:
    #     print(">>> python trans.py audio-file.mp3")
    # else:
    #     audio_file = sys.argv[1]
    #     if not os.path.exists(audio_file):
    #         print(f"Arquivo de áudio não encontrado: ", audio_file)
    #     else:
    #         transcribe_audio_seg(audio_file)
    audio_file = input("> Nome do arquivo: ")
    if os.path.exists(audio_file):
        transcribe_audio_seg(audio_file)
    else:
        print(f"Arquivo de áudio não encontrado: ", audio_file)

        
