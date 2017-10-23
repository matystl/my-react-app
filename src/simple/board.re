let component = ReasonReact.statelessComponent "Board";

let breakOnThree i => i mod 3 == 0 ? <br /> : <span />;

let make ::squares _children => {
  ...component,
  render: fun _self => {
    let foo = squares |> List.mapi (fun i s => <span> (breakOnThree i) <Square value=s /> </span>);
    <div> (ReasonReact.arrayToElement (Array.of_list foo)) </div>
  }
};
