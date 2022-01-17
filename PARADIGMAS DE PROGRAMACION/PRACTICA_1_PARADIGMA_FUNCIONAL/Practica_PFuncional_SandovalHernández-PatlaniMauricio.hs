    --Practica 1 Programación funcional en Haskell
    --Integrantes:
        -- Patlani Mauricio Adriana
        -- Sandoval Hernández Eduardo

    --Aplicación para obtener las soluciones a una ecuación cuadratica cuyos valores a, b y c son constantes enteras
        
    -- Esta función recibe dos numeros enteros y regresa el producto entre ellos
    multInt :: Float -> Float -> Float
    multInt x 0 = 0
    multInt x y |   y > 0 = x + multInt x (y-1)
                |   otherwise = -(x + multInt x (abs y - 1))
    
    --Esta función determina la manera más eficiente de realizar la función anterior
    multInt' :: (Float -> Float -> Float) -> (Float -> Float -> Float)
    multInt' f = g
        where g x y = if x >= y then f x y else f y x

    --Esta función eleva un número entero a una potencia entera
    pow :: Float -> Float -> Float
    pow x 0 = 1
    pow x y = multInt' multInt x (pow x (y-1))

    --Esta función devuelve el doble de un entero
    double :: Float -> Float
    double x = multInt x 2

    --Esta función calcula el determinante de una ecuación cuadrática
    discriminante :: Float -> Float -> Float -> Float
    discriminante = (\a -> (\b -> (\c -> pow b 2 - multInt' multInt (multInt' multInt a c) 4)))
    
    --Esta función recibe los valores de las constantes a, b y c de una ecuación cuadratica y obtiene sus raíces
    raices :: Float -> Float -> Float -> (Float,Float)
    raices a b c = ((-b + sqrt (discriminante a b c))/(double a),(-b - sqrt (discriminante a b c))/(double a))
    
    --Esta función determina si una ecuación cuadrática tiene solución usando como argumento el resultado del determinante
    tieneSol :: (Ord a,Num a) => a -> Bool
    tieneSol f  = if f >= 0 then True else False

    --Esta función muestra el resultado de una ecuación cuadrática
    eq :: Float -> Float -> Float -> (Float,Float)
    eq a b c    |   discriminante a b c >= 0 = raices a b c
                |   otherwise   =   error "***El resultado no esta en los numeros reales***"

    --Esta función también muestra el resultado de una ecuación cuadrática pero de otra forma
    eq2 :: Float -> Float -> Float -> [Char]
    eq2 a b c = if tieneSol (discriminante a b c) then "Las raices son: " ++ show (raices a b c)
                    else show "Las soluciones no estan en los numeros reales"

    --Esta función recibe como argumentos las constantes de la ecuación y uno de los resultados y lo evalua
    resul :: Float -> Float -> Float -> Float -> Float
    resul = (\a -> (\b -> (\c -> (\x -> (a*x^2 + b*x + c)))))
    
    --Usando como argumento el resultado de la función anterior, determina si es correcto o no
    evaluaR :: Float -> [Char]
    evaluaR x = if truncate x == 0 then show "Resultado correcto" else show "Resultado incorrecto"
