WITH TYPE_T AS (
    SELECT C.CAR_ID, C.CAR_TYPE, C.DAILY_FEE, D.DISCOUNT_RATE , D.DURATION_TYPE
    FROM CAR_RENTAL_COMPANY_CAR AS C
    
    JOIN CAR_RENTAL_COMPANY_DISCOUNT_PLAN AS D
    
    ON C.CAR_TYPE = D.CAR_TYPE
    
    WHERE (C.CAR_TYPE LIKE '세단' OR C.CAR_TYPE LIKE 'SUV')
    AND D.DURATION_TYPE LIKE "30%"
    
) , AVAIL_T AS (
    SELECT CAR_ID
    ,CASE 
        WHEN END_DATE < "2022-11-01" OR START_DATE > "2022-11-30" THEN "A"
        ELSE "N"
    END AS AVAIL
    FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
    
), CTE AS (
    SELECT CAR_ID, CAR_TYPE, DAILY_FEE, DISCOUNT_RATE
    FROM TYPE_T
    WHERE CAR_ID NOT IN (SELECT CAR_ID FROM AVAIL_T WHERE AVAIL LIKE "N")
    
)

SELECT CAR_ID, CAR_TYPE, ROUND(DAILY_FEE * (0.01 * (100 - DISCOUNT_RATE)) * 30) AS FEE FROM CTE
HAVING(FEE >= 500000 AND FEE <2000000)
ORDER BY 3 DESC, 2 , 1 DESC




# SELECT CAR_ID, CAR_TYPE, ROUND((DAILY_FEE * (0.01 * (100 - DISCOUNT_RATE))  * 30)) AS FEE FROM CTE
# HAVING (FEE >= 500000 AND FEE < 2000000)
# ORDER BY 3 DESC, 2, 1 DESC
























/*
-- 코드를 입력하세요
WITH AVAIL_CAR AS(

    SELECT DISTINCT CAR_ID FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
    WHERE CAR_ID NOT IN 
        (SELECT CAR_ID FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
            WHERE NOT (START_DATE > DATE_FORMAT("2022-11-30", "%Y-%m-%d") OR END_DATE < DATE_FORMAT("2022-11-01", "%Y-%m-%d")))
) , AVAIL_CAR2 AS (
    SELECT CAR_ID, R.CAR_TYPE,DAILY_FEE, DISCOUNT_RATE FROM AVAIL_CAR
    INNER JOIN CAR_RENTAL_COMPANY_CAR AS R
    USING (CAR_ID)
    
    INNER JOIN CAR_RENTAL_COMPANY_DISCOUNT_PLAN AS P
    ON R.CAR_TYPE = P.CAR_TYPE
    WHERE R.CAR_TYPE IN ('세단', 'SUV')
    AND DURATION_TYPE LIKE "30%"
) 



SELECT CAR_ID, CAR_TYPE, ROUND(30 * DAILY_FEE * (1 - 0.01 * DISCOUNT_RATE)) AS FEE  FROM AVAIL_CAR2
HAVING FEE >= 500000 AND FEE < 2000000
ORDER BY 3 DESC, CAR_TYPE ASC, CAR_ID DESC
*/