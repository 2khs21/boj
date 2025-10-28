# piece[U][D][F][B][L][R]

U, D, F, B, L, R = 0, 1, 2, 3, 4, 5
white, yellow, red, orange, green, blue = 0, 1, 2, 3, 4, 5
directions = [U, D, F, B, L, R]
opposite_pairs = [(U,D), (F,B), (L,R)]

from itertools import combinations

class CubePiece:
		def __init__(self, u=False, d=False, f=False, b=False, l=False, r=False):
				# 방향
				self.uDir = u
				self.dDir = d
				self.fDir = f
				self.bDir = b
				self.lDir = l
				self.rDir = r
				# 색상
				self.uColor = 'w'
				self.dColor = 'y'
				self.fColor = 'r'
				self.bColor = 'o'
				self.lColor = 'g'
				self.rColor = 'b'

		def has_faces(self, *faces):
				for f in faces:
						if f == 'U' and not self.uDir: return False
						if f == 'D' and not self.dDir: return False
						if f == 'F' and not self.fDir: return False
						if f == 'B' and not self.bDir: return False
						if f == 'L' and not self.lDir: return False
						if f == 'R' and not self.rDir: return False
				return True
		
		def get_color(self, face):
				if face == 'U': return self.uColor
				if face == 'D': return self.dColor
				if face == 'F': return self.fColor
				if face == 'B': return self.bColor
				if face == 'L': return self.lColor
				if face == 'R': return self.rColor
				return None

		def __repr__(self):
				result = []
				if self.uDir: result.append(f"U : {self.uColor}")
				if self.dDir: result.append(f"D : {self.dColor}")
				if self.fDir: result.append(f"F : {self.fColor}")
				if self.bDir: result.append(f"B : {self.bColor}")
				if self.lDir: result.append(f"L : {self.lColor}")
				if self.rDir: result.append(f"R : {self.rColor}")
				result.append("\n")
				return ", ".join(result)
		
		def rotate(self, face, clockwise=True):
				# 순환할 면 정의
				cycles = {
					'U': ['F', 'L', 'B', 'R'],
					'D': ['R', 'B', 'L', 'F'],
					'F': ['U', 'R', 'D', 'L'],
					'B': ['L', 'D', 'R', 'U'],
					'L': ['U', 'F', 'D', 'B'],
					'R': ['U', 'B', 'D', 'F']
					}
				 
				if not getattr(self, face.lower() + 'Dir'):
						return

				seq = cycles[face]
				if not clockwise:
						seq = seq[::-1]  # 반시계면 순서 뒤집기

				dirs = [getattr(self, s.lower() + 'Dir') for s in seq]
				colors = [getattr(self, s.lower() + 'Color') for s in seq]

				dirs = dirs[-1:] + dirs[:-1]
				colors = colors[-1:] + colors[:-1]

				for i, s in enumerate(seq):
						setattr(self, s.lower() + 'Dir', dirs[i])
						setattr(self, s.lower() + 'Color', colors[i])
		

def make_piece(faces):
		return CubePiece(
				u = U in faces,
				d = D in faces,
				f = F in faces,
				b = B in faces,
				l = L in faces,
				r = R in faces
		)


def print_upper_face(pieces):
    # U 면의 9칸 조합 (위에서 본 방향 기준)
    u_face_order = [
        [('U', 'B', 'L'), ('U', 'B'), ('U', 'B', 'R')],
        [('U', 'L'), ('U',), ('U', 'R')],
        [('U', 'F', 'L'), ('U', 'F'), ('U', 'F', 'R')]
    ]
    
    for row in u_face_order:
        line = ''
        for combo in row:
            found_piece = None

            for p in pieces:
                if p.has_faces(*combo):
                    face_count = sum([
                        p.uDir, p.dDir, p.fDir,
                        p.bDir, p.lDir, p.rDir
                    ])
                    if face_count == len(combo):
                        found_piece = p
                        break
            if found_piece:
                color = found_piece.get_color('U')
                line += color[0].lower()
            else:
                line += 'w' # 중앙 항상 w
        print(line)


def solution():
		T = int(input())
		for _ in range(T):
			n = int(input())
			rotations = list(input().strip().split())


			threePieces = []
			for comb in combinations(directions, 3):
				if any(a in comb and b in comb for a, b in opposite_pairs):
					continue
				threePieces.append(make_piece(comb))

			twoPieces = []
			for comb in combinations(directions, 2):
				if any(a in comb and b in comb for a, b in opposite_pairs):
					continue
				twoPieces.append(make_piece(comb))


			for rotation in rotations:
					face = rotation[0]
					clockwise = rotation[1] == '+'

					for piece in threePieces:
							piece.rotate(face, clockwise)
					for piece in twoPieces:
							piece.rotate(face, clockwise)
							
			print_upper_face(threePieces + twoPieces)

solution()