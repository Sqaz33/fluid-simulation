import numpy as np
import matplotlib.pyplot as plt


if __name__ == '__main__':
    # Параметры движения
    m = 1.0  # масса
    g = 9.8  # ускорение свободного падения
    k = 0.1  # коэффициент сопротивления
    dt = 0.01  # шаг времени
    
    # Начальные условия
    x, y = 0, 0
    vx, vy = 10, 10  # начальная скорость
    positions = [(x, y)]
    
    # x: Fg + Fd = m * ax
    # y: Fg + Fd = m * ay
    
    # x: -k * Vx = m * ax
    # y: -m * g - Vy * k  = m * ay
    
    # Моделирование
    for _ in range(1000):
        # ax = -k * vx / m  # ускорение по x
        # ay = -g - k * vy / m  # ускорение по y
        ax = (-k * vx) / m
        ay = -g - (vy * k) / m
        vx += ax * dt
        vy += ay * dt
        x += vx * dt
        y += vy * dt
        if y < 0:  # остановка при достижении земли
            break
        positions.append((x, y))

    # Отображение траектории
    positions = np.array(positions)
    plt.plot(positions[:, 0], positions[:, 1])
    plt.xlabel('x (м)')
    plt.ylabel('y (м)')
    plt.title('Траектория движения')
    plt.show()