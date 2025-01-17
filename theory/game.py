import pygame
import math

# Инициализация Pygame
pygame.init()

# Параметры экрана
screen_width, screen_height = 1500, 600
screen = pygame.display.set_mode((screen_width, screen_height))
pygame.display.set_caption("Движение материальной точки")

# Параметры точки
x, y = 0, 0  # начальное положение (в метрах)
vx, vy = 10, 10  # начальная скорость (м/с)
ax, ay = 0, -9.8  # ускорения (м/с²)
scale = 50  # коэффициент масштабирования (м -> пиксели)
dt = 0.02  # шаг времени (с)

# Цвета
background_color = (30, 30, 30)
point_color = (255, 0, 0)

# Основной цикл
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Обновление физики
    vx += ax * dt
    vy += ay * dt
    x += vx * dt
    y += vy * dt

    # Проверка "земли" (отражение от поверхности)
    if y < 0:
        y = 0
        vy = -vy * 0.8  # Потеря энергии при ударе (коэффициент упругости)

    # Преобразование координат в экранные
    pixel_x = int(x * scale)
    pixel_y = screen_height - int(y * scale)  # переворот оси Y

    # Рисование
    screen.fill(background_color)  # Очистка экрана
    pygame.draw.circle(screen, point_color, (pixel_x, pixel_y), 5)  # Отрисовка точки
    pygame.display.flip()  # Обновление экрана

    # Задержка для корректной скорости анимации
    pygame.time.delay(int(dt * 1000))

pygame.quit()
