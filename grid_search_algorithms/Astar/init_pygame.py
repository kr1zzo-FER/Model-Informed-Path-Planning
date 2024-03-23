import pygame, math, sys
import time

pygame.init()
pygame.font.init()

HEIGHT = 1018
WIDTH = 1244


rows = 320
cols = 320
grid = []
undo_log = []
start = None
end = None
display = pygame.display.set_mode((WIDTH, HEIGHT), 0, 32)
font = pygame.font.SysFont('Arial', 10)

WHITE = (255, 255, 255)
BLUE = (0, 0, 255)
LIGHT_BLUE = (135, 206, 250)
BLACK = (0, 0, 0)
GRAY = (128, 128, 128)
GREEN = (0, 255, 0)
RED = (255, 0, 0)
YELLOW = (255,255,0)
ORANGE = (255, 165, 0)

obstacle_display = True

text1 = font.render('Start/End Node (Right Click)', False, WHITE)
text2 = font.render('Coast inflation (Tab)', False, WHITE)
text3 = font.render('Start', False, WHITE)
text4 = font.render('Undo', False, WHITE)
text5 = font.render('Clear', False, WHITE)
text6 = font.render('Add obstacles (Left Click)', False, WHITE)

icon = pygame.image.load('./img/icon.png')
pygame.display.set_icon(icon)
pygame.display.set_caption('Path finder A*')

path_elements = []

background = pygame.image.load('assets/kvarner_bw.png')
background_display = pygame.image.load('assets/kvarner.png')
#background = pygame.transform.scale(background, (self.Mapw, self.Maph))
display.fill((0, 0, 0))
display.blit(background_display, (0, 0))
screensurf = pygame.display.get_surface()

