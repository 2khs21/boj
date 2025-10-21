import math

def solution(numer1, denom1, numer2, denom2):
		answer = []
		
		upside = numer1 * denom2 + numer2 * denom1
		downside = denom1 * denom2

		gcd = math.gcd(upside, downside)

		answer = [upside / gcd, downside / gcd]
		
		


		return answer