import pygame
import random

# Initialize pygame
pygame.init()

# Set up some constants
SCREEN_WIDTH = 800
SCREEN_HEIGHT = 600
GROUND_HEIGHT = SCREEN_HEIGHT - 100
DINO_HEIGHT = 50
DINO_WIDTH = 50
DINO_JUMP_VELOCITY = -15
GRAVITY = 1
OBSTACLE_SPAWN_RATE = 120

# Set up some colors
WHITE = (255, 255, 255)
GREEN = (0, 255, 0)
RED = (255, 0, 0)

# Create the screen
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption("Dino Game")

# Create the dino
dino_rect = pygame.Rect(SCREEN_WIDTH // 2 - DINO_WIDTH // 2, GROUND_HEIGHT, DINO_WIDTH, DINO_HEIGHT)
dino_velocity = 0
is_jumping = False

# Create the obstacles
obstacle_group = pygame.sprite.Group()

# Game loop
running = True
while running:
    # Handle events
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE:
                is_jumping = True
                dino_velocity = DINO_JUMP_VELOCITY

    # Update the game state
    dino_rect.y += dino_velocity
    dino_velocity += GRAVITY
    if dino_rect.y > GROUND_HEIGHT:
        dino_rect.y = GROUND_HEIGHT
        is_jumping = False
    if not is_jumping:
        if random.randint(0, OBSTACLE_SPAWN_RATE) == 0:
            obstacle = pygame.sprite.Sprite()
            obstacle.image = pygame.Surface((50, random.randint(50, 100)))
            obstacle.image.fill(RED)
            obstacle.rect = obstacle.image.get_rect()
            obstacle.rect.x = SCREEN_WIDTH
            obstacle.rect.y = GROUND_HEIGHT - obstacle.rect.height
            obstacle_group.add(obstacle)
    obstacle_group.update()
    for obstacle in obstacle_group:
        if pygame.sprite.collide_rect(dino_rect, obstacle):
            running = False

    # Draw everything
    screen.fill(WHITE)
    pygame.draw.rect(screen, GREEN, dino_rect)
    obstacle_group.draw(screen)

    # Flip the display
    pygame.display.flip()

# Quit pygame
pygame.quit()