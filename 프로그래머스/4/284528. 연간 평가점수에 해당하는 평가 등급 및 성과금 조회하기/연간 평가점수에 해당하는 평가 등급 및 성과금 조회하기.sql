-- 코드를 작성해주세요
WITH T AS (

SELECT E.EMP_NO, E.EMP_NAME,  E.SAL
    , SUM(SCORE) AS S_SCORE    
          ,CASE 
               WHEN SUM(SCORE) >= 192 THEN 'S'
               WHEN SUM(SCORE) >= 180 THEN 'A'
                WHEN SUM(SCORE) >= 160 THEN 'B'
                ELSE 'C'
           END AS GRADE
FROM HR_EMPLOYEES AS E
INNER JOIN HR_GRADE AS G
ON E.EMP_NO = G.EMP_NO
    
GROUP BY E.EMP_NO
)


SELECT EMP_NO, EMP_NAME, GRADE
, CASE WHEN GRADE = 'S' THEN SAL * 0.2
 WHEN GRADE = 'A' THEN SAL * 0.15
 WHEN GRADE = 'B' THEN SAL * 0.1
 ELSE 0
END AS BONUS
FROM T
ORDER BY EMP_NO