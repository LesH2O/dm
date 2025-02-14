let mcnuggets x y =
  let rec pgcd a b =
    if a mod b = 0 then b
    else pgcd b (a mod b)
  in if (pgcd x y) = 1 then (
    if x=1 or y=1 then failwith "avec 1 c'est facile, on part a l'infini"
    else (x*y-(x+y))) (* observation sur un echantillon de beaucoup d'essais -> complexité constante *)
  else failwith "si ils sont multiples, on part a l'infini";;


mcnuggets 4 7;;
mcnuggets 1 2;;
mcnuggets 0 5;;






let existe_somme t =
  let n = Array.length t in
  let res = ref 0 in
  for i=2 to (n-1) do
    for j=1 to (i-1) do
      for k=0 to (j-1) do
        if t.(k)=t.(j)+t.(i) then res:= !res+1
        else (if t.(j)=t.(i)+t.(k) then res := !res+1
              else (if t.(i)=t.(k)+t.(j) then res := !res+1
                    else res := !res));
             
      done;
    done;
  done;
  (!res<>0);;

existe_somme [|0;0;0|];;
existe_somme [|1;2;4|];;
existe_somme [|1;3;2|];;




let fin_commune str1 str2 =
  let n = ref 0 in
  let len1 = String.length str1 in
  let len2 = String.length str2 in
  let max = (if len1>len2 then len2 else len1) in
  let i = ref 1 in
  let egaux = ref 1 in
  while !egaux=1 && !i<max do (
    if str1.[len1- !i]=str2.[len2- !i] then n := !n+1
    else egaux:= 0;
    i := !i+1;)
  done; 
  !n;;

fin_commune "coucou" "j'ai mal au cou";;
fin_commune "never" "give you up";;    




type fraction =  { num : int; den : int};;

let simplifiable t =
  let n = Array.length t in
  let res = ref false in
  for i =1 to (n-1) do 
    if (t.(i)).den = 0 then failwith "division par 0"
    else (
      for j = 0 to (i-1) do (
        if (t.(j)).den = 0 then failwith "division par 0"
        else ( if ((t.(i)).den)*((t.(j)).num)=((t.(j)).den)*((t.(i)).num) then res := true
               else res := !res))
      done;)
  done;
  !res;;


      
    


