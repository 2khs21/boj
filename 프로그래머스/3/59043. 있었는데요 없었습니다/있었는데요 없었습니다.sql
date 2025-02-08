-- 코드를 입력하세요
SELECT I.ANIMAL_ID, I.NAME #  , I.DATETIME, O.DATETIME 
FROM ANIMAL_INS AS I

INNER JOIN ANIMAL_OUTS AS O
ON I.ANIMAL_ID = O.ANIMAL_ID

# WHERE DATEDIFF(I.DATETIME, O.DATETIME) > 0
WHERE I.DATETIME > O.DATETIME
ORDER BY I.DATETIME