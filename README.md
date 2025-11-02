# Audio-Classficitaion

## Overview

This project focuses on building an audio classification system using the UrbanSound8K dataset. The goal is to classify different types of urban sounds, such as dog barks, car horns, drilling, and more, using machine learning techniques. The workflow includes preprocessing audio data, extracting features (MFCCs), and training classification models.

## Features

- **Audio Feature Extraction:** Uses Mel-Frequency Cepstral Coefficients (MFCCs) to represent and analyze audio signals.
- **Data Visualization:** Includes waveform and feature visualization for better understanding of audio data.
- **Dataset Handling:** Processes the UrbanSound8K dataset with metadata for class labels.
- **Model Training:** Prepares features for supervised learning models.

## Dataset

- UrbanSound8K: [https://urbansounddataset.weebly.com/urbansound8k.html](https://urbansounddataset.weebly.com/urbansound8k.html)
- Contains 8,732 labeled sound excerpts (<=4s) from 10 classes.

## Workflow

1. **Install Dependencies:**  
   - `librosa`, `scipy`, `resampy`, and other required Python packages.
2. **Read and Visualize Audio:**  
   - Load audio files and visualize waveforms.
3. **Extract Features:**  
   - Extract MFCC features for each audio sample.
4. **Prepare Dataset:**  
   - Convert features and labels into arrays for model training.
5. **Model Training (future scope):**  
   - Train and evaluate machine learning models for classification.

## Usage

1. Clone the repository:
   ```bash
   git clone https://github.com/MehediEEE45/Audio-Classficitaion.git
   ```
2. Install required libraries:
   ```bash
   pip install librosa scipy resampy
   ```
3. Download and extract the UrbanSound8K dataset.
4. Edit paths in the notebook to match your dataset location.
5. Run the notebook `Audio_classification.ipynb` step by step.

## Folder Structure

- `Audio_classification.ipynb` - Main Jupyter notebook for feature extraction and data processing.
- `UrbanSound8K/` - Folder containing audio files and metadata.
- Other supporting files and models.

## Requirements

- Python 3.7+
- librosa
- scipy
- resampy
- pandas
- numpy
- tqdm
- matplotlib

## Results

- MFCC features are extracted for each audio sample.
- Dataset is prepared for classification tasks.
- Data distribution across classes is visualized.

## Future Work

- Build and train deep learning models for audio classification.
- Evaluate performance and improve accuracy.
- Deploy as a web or mobile application.

## License

This project is licensed under the MIT License.

## Author

MehediEEE45
