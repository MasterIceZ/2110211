vertices = [
    [1, -1, 3], [1, 1, 3], [-1, -1, 3], [-1, 1, 3],  # 0 to 3, upper z face
    [1, -3, 1], [1, -1, 1], [1, 1, 1], [1, 3, 1],    # 4 to 7
    [-1, -3, 1], [-1, -1, 1], [-1, 1, 1], [-1, 3, 1], # 8 to 11
    [1, -3, -1], [1, -1, -1], [1, 1, -1], [1, 3, -1], # 12 to 15
    [-1, -3, -1], [-1, -1, -1], [-1, 1, -1], [-1, 3, -1], # 16 to 19
    [1, -1, -3], [1, 1, -3], [-1, -1, -3], [-1, 1, -3], # 20 to 23, lower z face
    [3, -1, 1], [3, 1, 1], [3, -1, -1], [3, 1, -1],   # 24 to 27, right x face
    [-3, -1, 1], [-3, 1, 1], [-3, -1, -1], [-3, 1, -1] # 28 to 31, left x face
]

faces = [
    # Extreme z faces
    [0, 2, 3], [0, 3, 1],       # Split [0, 2, 3, 1] into two triangles
    [20, 21, 23], [20, 23, 22], # Split [20, 21, 23, 22] into two triangles
    
    # Extreme x faces
    [24, 25, 27], [24, 27, 26], # Split [24, 25, 27, 26] into two triangles
    [28, 30, 31], [28, 31, 29], # Split [28, 30, 31, 29] into two triangles
    
    # Extreme y faces
    [8, 4, 12], [8, 12, 16],   # Split [8, 4, 12, 16] into two triangles
    [7, 11, 19], [7, 19, 15],   # Split [7, 11, 19, 15] into two triangles
    
    # Top wedge faces
    [0, 1, 25], [0, 25, 24],    # Split [0, 1, 25, 24] into two triangles
    [1, 3, 11], [1, 11, 7],     # Split [1, 3, 11, 7] into two triangles
    [3, 2, 28], [3, 28, 29],    # Split [3, 2, 28, 29] into two triangles
    [2, 0, 4], [2, 4, 8],       # Split [2, 0, 4, 8] into two triangles
    
    # Bottom wedge faces
    [20, 26, 27], [20, 27, 21], # Split [20, 26, 27, 21] into two triangles
    [15, 19, 23], [15, 23, 21], # Split [15, 19, 23, 21] into two triangles
    [31, 30, 22], [31, 22, 23], # Split [31, 30, 22, 23] into two triangles
    [16, 12, 20], [16, 20, 22], # Split [16, 12, 20, 22] into two triangles
    
    # Central wedge faces
    [4, 24, 26], [4, 26, 12],   # Split [4, 24, 26, 12] into two triangles
    [25, 7, 15], [25, 15, 27],   # Split [25, 7, 15, 27] into two triangles
    [11, 29, 31], [11, 31, 19],  # Split [11, 29, 31, 19] into two triangles
    [28, 8, 16], [28, 16, 30],   # Split [28, 8, 16, 30] into two triangles
    
    # Top pyramids
    [4, 0, 24], [4, 24, -1],     # Split [4, 0, 24, -1] into two triangles
    [1, 7, 25], [1, 25, -1],     # Split [1, 7, 25, -1] into two triangles
    [11, 3, 29], [11, 29, -1],   # Split [11, 3, 29, -1] into two triangles
    [28, 2, 8], [28, 8, -1],     # Split [28, 2, 8, -1] into two triangles
    
    # Lower pyramids
    [12, 26, 20], [12, 20, -1], # Split [12, 26, 20, -1] into two triangles
    [27, 15, 21], [27, 21, -1], # Split [27, 15, 21, -1] into two triangles
    [19, 31, 23], [19, 23, -1], # Split [19, 31, 23, -1] into two triangles
    [30, 16, 22], [30, 22, -1]  # Split [30, 16, 22, -1] into two triangles
]

s = 0.3

vtx = []
for v in vertices:
    #print(f"renderer.getVertexContainer(0).addVertex({v[0] * s}, {v[1] * s}, {v[2] * s});")
    vtx.append([v[0] * s, v[1] * s, v[2] * s])

print(vtx)
print()

fcs = []
for t in faces:
    # print(f"renderer.getVertexContainer(0).addFace({t[0]}, {t[1]}, {t[2]});")
    fcs.append([t[0], t[1], t[2]])
print(fcs)
