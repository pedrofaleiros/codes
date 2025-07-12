# criar ambiente
python -m venv venv

# Instalar ffmpeg
sudo apt update && sudo apt install -y ffmpeg

# Instalar whisper
pip install git+https://github.com/openai/whisper.git 
