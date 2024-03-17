# dark blue for end nodes
# light blue for path
# dark green for currently searched nodes
# light green for already searched nodes
# white for empty
import pygame, math, sys
from a_star import *

pygame.init()
pygame.font.init()

HEIGHT = 1000
WIDTH = 1000

rows = 80
cols = 80
grid = []
undo_log = []
start = None
end = None
display = pygame.display.set_mode((WIDTH, HEIGHT), 0, 32)

WHITE = (255, 255, 255)
BLUE = (0, 0, 255)
LIGHT_BLUE = (135, 206, 250)
BLACK = (0, 0, 0)
GRAY = (128, 128, 128)
GREEN = (0, 255, 0)
RED = (255, 0, 0)
YELLOW = (255,255,0)

font = pygame.font.SysFont('Arial', 10)
text1 = font.render('Start/End Node (Right Click)', False, BLACK)
text2 = font.render('Wall Node (Left Click)', False, BLACK)
text3 = font.render('Start', False, WHITE)
text4 = font.render('Undo', False, WHITE)
text5 = font.render('Clear', False, WHITE)

icon = pygame.image.load('./img/icon.png')
pygame.display.set_icon(icon)
pygame.display.set_caption('Pathfinder')

path_elements = []

def update_display():
  display.fill(WHITE)

  pygame.draw.rect(display, BLUE, (10, 5, 10, 10))
  pygame.draw.rect(display, BLACK, (200, 5, 10, 10))
  display.blit(text1, (25, 5))
  display.blit(text2, (215, 5))

  # Buttons
  pygame.draw.rect(display, BLACK, (355, 7, 40, 10))
  pygame.draw.rect(display, BLACK, (435, 7, 40, 10))
  pygame.draw.rect(display, BLACK, (515, 7, 40, 10))

  display.blit(text3, (362, 6))
  display.blit(text4, (443, 6))
  display.blit(text5, (524, 6))



def reset_grid():
  global grid, start, end, undo_log
  grid, undo_log, start, end = [], [], None, None

  for i in range(rows):
    row_nodes = []
    for j in range(cols):
      node = Node(grid, j, i)
      row_nodes.append(node)
    grid.append(row_nodes)
  update_grid(display, grid)

def get_neighbors(grid, row, col):
    neighbors = []
    neigbour_position = []
    # Define the possible relative positions of neighbors
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0), (-1,-1), (1, 1), (-1, 1), (1, -1) ]  
    
    # Iterate through each direction and check if the neighbor is within the grid bounds
    for dr, dc in directions:
        new_row, new_col = row + dr, col + dc
        if 0 <= new_row < len(grid) and 0 <= new_col < len(grid[0]):
            neighbors.append([grid[new_row][new_col], new_row, new_col])
    return neighbors

def draw_walls(i,j, rect_width, rect_height, grid):
        
        #print("uso")
        #print(path_ij)

        neighbours = get_neighbors(grid, i, j)

        #path_elements = []

        for neighbour in neighbours:
         
         #print("neigbour")
         if neighbour[0].type != 'wall':

          grid[neighbour[1]][neighbour[2]].type = 'wall_area_1'
          pygame.draw.rect(display, RED, (neighbour[2] * rect_width + 1, neighbour[1] * rect_height + 21, rect_width, rect_height))
           
          neighbours_2 = get_neighbors(grid, neighbour[1], neighbour[2])
          
          for neighbour_2 in neighbours_2:

            if neighbour_2[0].type == 'path':
              path_elements.append(neighbour_2)

            if neighbour_2[0].type != 'wall' and neighbour_2[0].type != 'wall_area_1':
              grid[neighbour_2[1]][neighbour_2[2]].type = 'wall_area_2'
              pygame.draw.rect(display, YELLOW, (neighbour_2[2] * rect_width + 1, neighbour_2[1] * rect_height + 21, rect_width, rect_height))

              for neighbour_3 in get_neighbors(grid, neighbour_2[1], neighbour_2[2]):
                
                if neighbour_3[0].type == 'path':
                    print(neighbour_3[1], neighbour_3[2])
                    path_elements.append(neighbour_3)

                if neighbour_3[0].type != 'wall' and neighbour_3[0].type != 'wall_area_1' and neighbour_3[0].type != 'wall_area_2':
                  grid[neighbour_3[1]][neighbour_3[2]].type = 'wall_area_3'
                  pygame.draw.rect(display, GREEN, (neighbour_3[2] * rect_width + 1, neighbour_3[1] * rect_height + 21, rect_width, rect_height))

        for path_element in path_elements:
          try:
            #print("path_element:")
            #print(path_element[1], path_element[2])
            pygame.draw.rect(display, BLUE, (path_element[2] * rect_width + 1, path_element[1] * rect_height + 21, rect_width, rect_height))
          except Exception as e:
            print(e)
        return

def update_grid(display, grid):

  update_display()
  rect_width = (WIDTH - 1)/cols
  rect_height = (HEIGHT - 21)/cols
  


  for i in range(rows):
    for j in range(cols):
      color = None
      node = grid[i][j]
      
      
      if node == start or node == end:
        color = LIGHT_BLUE
        pygame.draw.rect(display, color, (j * rect_width + 1, i * rect_height + 21, rect_width, rect_height))
      
      if node.type == 'wall_area_1' or node.type == 'wall_area_2' or node.type == 'wall_area_3':
        pass
      
      if node.type == 'path':
          color = BLUE
          pygame.draw.rect(display, color, (j * rect_width + 1, i * rect_height + 21, rect_width, rect_height))

      if node.type == 'wall':
        color = BLACK
        pygame.draw.rect(display, color, (j * rect_width + 1, i * rect_height + 21, rect_width, rect_height))
        draw_walls(i,j, rect_width, rect_height, grid)
      


  for i in range(len(grid) + 1):
    pygame.draw.rect(display, GRAY, (i * rect_width, 20, 1, HEIGHT))
    pygame.draw.rect(display, GRAY, (0, i * rect_height + 20, WIDTH, 1))

  pygame.display.update()

reset_grid()
update_grid(display, grid)

def draw_tile(x, y, tile_type):
  global start, end, undo_log
  clear_path_nodes()
  
  row = ((y - 20) * rows)//(HEIGHT - 20)
  col = (x * cols)//WIDTH
  node = grid[row][col]

  if row < 0 or col < 0 or row >= rows or col >= cols or node.type == 'wall' or node == start or node == end:
    return
  elif tile_type == 'endpoint' and start and end:
    return

  if tile_type == 'wall':
    grid[row][col].type = 'wall'
  elif tile_type == 'endpoint':
    if not start:
      start = node
    elif not end:
      end = node

  undo_log.append(node)
  update_grid(display, grid)

def pathfind():
  if not start or not end:
    print('Please mark both endpoint nodes.')
    return
  path = a_star(grid, start, end)
  if not path:
    print('No possible paths.')
    return
  else:
    distance = round(path[-1].f_score, 2)
    if distance % 1 == 0:
      distance = int(distance)
    print('Path found with distance ' + str(distance) + '.')
  for node in path:
    print("current_type:")
    print(node.type)
    if node != start and node != end:
      node.type = 'path'
      print("new type:")
      print(node.type)
  print("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nupdate grid:")
  update_grid(display, grid)

def clear_path_nodes():
  for i in range(rows):
    for j in range(cols):
      node = grid[i][j]
      if node.type == 'path':
        node.type = 'road'
            

while True:

  for event in pygame.event.get():

    if event.type == pygame.QUIT:
      pygame.quit()
      sys.exit()

    # Test for click on start and clear button
    if event.type == pygame.MOUSEBUTTONDOWN and event.button == 1:
      mouse_pos = pygame.mouse.get_pos()
      x = mouse_pos[0]
      y = mouse_pos[1]
      
      # Start button
      if x >= 355 and x <= 395 and y >= 7 and y <= 17:
        pathfind()
      # Undo button
        
      elif x >= 435 and x <= 475 and y >= 7 and y <= 17:
        if len(undo_log) > 0:
          node = undo_log[-1]
          node.type = 'road'
          if node == start or node == end:
            if end:
              end = None
            elif start:
              start = None 
          update_grid(display, grid)
          undo_log.pop(-1)

      # Clear button
      elif x >= 515 and x <= 555 and y >= 7 and y <= 17:
        path_elements = []
        reset_grid()

    # Right click adds start/end node
    if event.type == pygame.MOUSEBUTTONDOWN and event.button == 3:
      mouse_pos = pygame.mouse.get_pos()
      x = mouse_pos[0]
      y = mouse_pos[1]
      draw_tile(x, y, 'endpoint')

    # Left click adds wall node
    if pygame.mouse.get_pressed()[0]:
      path_elements = []
      mouse_pos = pygame.mouse.get_pos()
      x = mouse_pos[0]
      y = mouse_pos[1]
      draw_tile(x, y, 'wall')
