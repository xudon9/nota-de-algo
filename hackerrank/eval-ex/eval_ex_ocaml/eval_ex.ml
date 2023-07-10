(* https://www.hackerrank.com/challenges/eval-ex/ *)
module L = Base.List
module In = In_channel
module Out = Out_channel

let calc n x =
  let step (sum, term) i =
    let term' = term *. x /. Float.of_int i in
    (sum +. term', term')
  in
  let result = fst (L.fold ~init:(1., 1.) ~f:step (L.range 1 n)) in
  let () = Stdio.printf "%F\n" result in
  Out.(flush stdout)

let rec read_and_calc () =
  let line = In.(input_line stdin) in
  match line with
  | None -> ()
  | Some x ->
      calc 10 (Float.of_string x);
      read_and_calc ()

let () =
  let _ = In.(input_line stdin) in
  read_and_calc ()
