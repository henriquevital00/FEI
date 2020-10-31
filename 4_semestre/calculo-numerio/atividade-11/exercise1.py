from scipy import signal
import matplotlib.pyplot as plt
import numpy as np
from scipy.fftpack import fft, ifft

Fs=100
t = 1/ Fs
n=64
x=np.linspace(0.0, n*t, n)
signal.square
y=10*np.cos(25*2.0*np.pi*x)
yf=fft(y)
xf=np.linspace(0.0, 1.0/(2.0*t), n//2)
plt.title("Signal original")
plt.plot(x, y)
plt.axis([0, 1, -1, 1])
plt.show()
plt.title("Sinal FFT")
plt.plot(xf, 2.0/n*np.abs(yf[0:n//2]))
plt.axis([0, 50, 0, 1])
plt.grid()
plt.show()

