#!/usr/bin/env python3
from scipy import signal
import matplotlib.pyplot as plt
import numpy as np
from scipy.fftpack import fft, ifft
from scipy.io import wavfile

fs, data = wavfile.read("./musica.wav")
fs=4096
nfft=1024

plt.specgram(data, nfft, fs, noverlap=7*nfft//8)
plt.show()

fff, pxx_den = signal.periodogram(data, fs)
plt.plot(fff, pxx_den)
plt.axis([80, 140, 0, 5000])
plt.show()


