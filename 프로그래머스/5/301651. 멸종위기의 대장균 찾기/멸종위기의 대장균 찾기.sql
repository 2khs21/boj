
WITH RECURSIVE CTE AS (

    SELECT ID, PARENT_ID, 1 AS GENERATION
    FROM ECOLI_DATA
    WHERE PARENT_ID IS NULL
    UNION ALL
    
    SELECT E.ID, E.PARENT_ID, CTE.GENERATION + 1 AS GENERATION
    
    FROM ECOLI_DATA AS E
    
    JOIN CTE
    
    ON CTE.ID = E.PARENT_ID 
    
    
), P_ID AS (
    SELECT PARENT_ID FROM ECOLI_DATA
    WHERE PARENT_ID IS NOT NULL
), NP_ID AS (
    SELECT ID FROM ECOLI_DATA
    
    WHERE ID NOT IN (SELECT * FROM P_ID)
)





SELECT COUNT(*) AS COUNT, GENERATION FROM CTE
WHERE ID IN (SELECT * FROM NP_ID)
GROUP BY GENERATION
ORDER BY 2


















/*WITH RECURSIVE CTE AS (
    SELECT ID, PARENT_ID, 1 AS GENERATION FROM ECOLI_DATA
    WHERE PARENT_ID IS NULL
    
    UNION ALL


    SELECT E.ID, E.PARENT_ID, CTE.GENERATION + 1 AS GENERATION
    FROM ECOLI_DATA AS E
    INNER JOIN CTE
    
    ON CTE.ID = E.PARENT_ID

), CTE2 AS (

    SELECT C1.ID, C1.GENERATION
    FROM CTE AS C1
    WHERE ID NOT IN (SELECT PARENT_ID FROM CTE WHERE PARENT_ID IS NOT NULL)
    
    )

SELECT COUNT(ID) AS COUNT, GENERATION FROM CTE2 GROUP BY GENERATION
ORDER BY 2
*/

/*

WITH RECURSIVE CTE AS (

    SELECT ID, PARENT_ID, 1 AS GEN FROM ECOLI_DATA
    WHERE PARENT_ID IS NULL
    
    UNION ALL

    SELECT E.ID, E.PARENT_ID, CTE.GEN + 1 AS GEN FROM ECOLI_DATA AS E
    INNER JOIN CTE
    ON CTE.ID = E.PARENT_ID
), T AS (

    SELECT COUNT(ID) AS COUNT , GEN AS GENERATION FROM CTE
    WHERE ID NOT IN (SELECT PARENT_ID FROM CTE WHERE PARENT_ID IS NOT NULL)
    GROUP BY GEN
)

SELECT * FROM T


*/