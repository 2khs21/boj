WITH RECURSIVE cte(ID, PARENT_ID, GEN) AS (
    SELECT ID, PARENT_ID, 1 AS GEN
    FROM ECOLI_DATA
    WHERE PARENT_ID IS NULL
    UNION ALL
    
    SELECT ed.ID, ed.PARENT_ID, cte.GEN + 1
    FROM ECOLI_DATA ed
    JOIN cte ON ed.PARENT_ID = cte.ID
)

# SELECT * FROM cte

# SELECT DISTINCT PARENT_ID FROM cte
# WHERE PARENT_ID IS NOT NULL;

# SELECT ID FROM ECOLI_DATA WHERE ID NOT IN (
#     SELECT DISTINCT PARENT_ID FROM cte
#     WHERE PARENT_ID IS NOT NULL)

SELECT COUNT(ID) AS COUNT, GEN AS GENERATION
FROM cte 
WHERE ID IN (
    SELECT ID FROM ECOLI_DATA WHERE ID NOT IN (
        SELECT DISTINCT PARENT_ID FROM cte
        WHERE PARENT_ID IS NOT NULL
        )
    )
GROUP BY GEN


# WITH RECURSIVE cte(ID, PARENT_ID, GEN) AS (
#     SELECT ID, PARENT_ID, 1 AS GEN
#     FROM ECOLI_DATA
#     WHERE PARENT_ID IS NULL
#     UNION ALL
#     SELECT ed.ID, ed.PARENT_ID, cte.GEN + 1
#     FROM ECOLI_DATA ed
#     JOIN cte ON ed.PARENT_ID = cte.ID
# )

# SELECT COUNT(ed.ID) AS COUNT, cte.GEN AS GENERATION  
# FROM ECOLI_DATA ed
# JOIN cte ON cte.ID = ed.ID
# WHERE cte.ID NOT IN (SELECT DISTINCT PARENT_ID 
# FROM CTE
# WHERE PARENT_ID IS NOT NULL)
# GROUP BY GEN
# ;