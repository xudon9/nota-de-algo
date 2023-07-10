(*https://www.hackerrank.com/challenges/area-under-curves-and-volume-of-revolving-a-curv/*)
module In = Stdio.In_channel
module Out = Stdio.Out_channel

let read_int_list_line () =
  let line = read_line () in
  let strs = Str.(split (regexp " +") line) in
  List.map int_of_string strs

let poly alist blist x =
  let vals = List.map2 (fun a b -> a *. (x ** b)) alist blist in
  List.fold_left ( +. ) 0. vals

let integral al bl left right stride =
  let il = Float.of_int left in
  let ir = Float.of_int right in
  let rec step cur ((area, volume) as acc) =
    if cur >= ir then acc
    else
      let a = poly al bl cur in
      step (cur +. stride)
        (area +. (a *. stride), volume +. (stride *. Float.pi *. a *. a))
  in
  step il (0., 0.)

let () =
  let al = List.map Float.of_int (read_int_list_line ()) in
  let bl = List.map Float.of_int (read_int_list_line ()) in
  let range = read_int_list_line () in
  match range with
  | [ x; y ] ->
      let area, volume = integral al bl x y 0.001 in
      Out.printf "%f\n%f\n" area volume
  | _ -> exit 1
