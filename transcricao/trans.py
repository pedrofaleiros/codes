import whisper
import sys
import os
import argparse
import warnings

# 'tiny' 'base' 'small', 'medium', 'large'

warnings.filterwarnings(
    "ignore", message="FP16 is not supported on CPU; using FP32 instead"
)

def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Transcreve áudio com Whisper e salva em ./transcription"
    )

    parser.add_argument(
        "audio",
        help="Arquivo de áudio a ser transcrito (ex.: meu_audio.mp3)",
    )

    parser.add_argument(
        "-m",
        "--model",
        default="medium",
        choices=["tiny", "base", "small", "medium", "large"],
        help="Nome do modelo Whisper (padrão: medium)",
    )

    parser.add_argument(
        "-v",
        "--verbose",
        action="store_true",
        help="Exibe detalhes da transcrição (padrão: desligado)",
    )

    parser.add_argument(
        "-t",
        "--temperature",
        type=float,
        default=0.0,
        help="Temperatura do decodificador (padrão: 0.0)",
    )

    parser.add_argument(
        "-p",
        "--prompt",
        default="",
        help='Prompt inicial a ser fornecido ao modelo (padrão: "")',
    )

    return parser.parse_args()

def transcribe_audio(audio_file: str, model_name: str, verbose: bool,
                     temperature: float, initial_prompt: str) -> None:

    print("> Carregando modelo…")
    model = whisper.load_model(model_name)

    print("> Transcrevendo…")
    result = model.transcribe(
        audio_file,
        language="pt",
        temperature=temperature,
        verbose=verbose,
        initial_prompt=initial_prompt or None,
    )

    print("> Salvando…")
    base_name = os.path.splitext(os.path.basename(audio_file))[0]
    output_dir = "./transcription"
    os.makedirs(output_dir, exist_ok=True)
    text_file = os.path.join(output_dir, f"{base_name}-{model_name[0]}.txt")

    with open(text_file, "w", encoding="utf-8") as f:
        for seg in result["segments"]:
            f.write(seg["text"].strip() + "\n")

    print(f"> Salvo em: {text_file}")

if __name__ == "__main__":
    args = parse_args()

    if not os.path.exists(args.audio):
        sys.exit(f"Arquivo de áudio não encontrado: {args.audio}")

    transcribe_audio(
        audio_file=args.audio,
        model_name=args.model,
        verbose=args.verbose,
        temperature=args.temperature,
        initial_prompt=args.prompt,
    )
