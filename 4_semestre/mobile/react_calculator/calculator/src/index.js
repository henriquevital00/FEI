/**
 * @class       : index
 * @author      : Henrique Vital Carvalho (henriquevital1000@hotmail.com)
 * @created     : sábado out 24, 2020 16:40:04 -03
 * @description : index
 */

import React from 'react';
import ReactDOM from 'react-dom';
import Botao from "./Botao";
import Soma from "./Soma";
import Subtracao from "./Subtracao"
import Divisao from "./Divisao"
import Multiplicacao from "./Multiplicacao"

class App extends React.Component {
    constructor(props) {
        super(props);
        //this.pressionar = this.pressionar.bind(this);
        this.state={
            texto:"",
            number1: undefined,
            number2: undefined,
            operation: null
        }
    }
    pressionar(number){
        this.setState(({texto: this.state.texto + String(number)}))
    }

    clear(){
        this.setState(({texto: ""}))
    }

    soma(){
        this.setState({number1: parseInt(this.state.texto)});
        this.clear();
        this.setState({operation: new Soma()})
    }

    divisao(){
        this.setState({number1: parseInt(this.state.texto)});
        this.clear();
        this.setState({operation: new Divisao()})
    }

    multiplicacao(){
        this.setState({number1: parseInt(this.state.texto)});
        this.clear();
        this.setState({operation: new Multiplicacao()})
    }

    divisao(){
        this.setState({number1: parseInt(this.state.texto)});
        this.clear();
        this.setState({operation: new Divisao()})
    }

    subtracao(){
        this.setState({number1: parseInt(this.state.texto)});
        this.clear();
        this.setState({operation: new Subtracao()})
    }

    resultado(){
        this.setState({number2: parseInt(this.state.texto)}, ()=>{
            this.setState({texto: this.state.operation.calcula(this.state.number1, this.state.number2)});
        });
    }

    render(){
        return(
            <div>
                <h1>Calculadora</h1>
                <table>
                    <tr>
                        <td colSpan="4">
                            <input
                                style={{width:170,
                                    fontSize:"18pt"}}
                                type="text"
                                value={this.state.texto}/>
                        </td>
                    </tr>
                    <tr>
                        <td><Botao clique={()=>this.pressionar(7)}>7</Botao></td>
                        <td><Botao clique={()=>this.pressionar(8)}>8</Botao></td>
                        <td><Botao clique={()=>this.pressionar(9)}>9</Botao></td>
                        <td><Botao clique={()=>this.divisao()}>/</Botao></td>
                    </tr>
                    <tr>
                        <td><Botao clique={()=>this.pressionar(4)}>4</Botao></td>
                        <td><Botao clique={()=>this.pressionar(5)}>5</Botao></td>
                        <td><Botao clique={()=>this.pressionar(6)}>6</Botao></td>
                        <td><Botao clique={()=>this.multiplicacao()}>x</Botao></td>
                    </tr>
                    <tr>
                        <td><Botao clique={()=>this.pressionar(1)}>1</Botao></td>
                        <td><Botao clique={()=>this.pressionar(2)}>2</Botao></td>
                        <td><Botao clique={()=>this.pressionar(3)}>3</Botao></td>
                        <td><Botao clique={()=>this.subtracao()}>-</Botao></td>
                    </tr>
                    <tr>
                        <td><Botao clique={()=>this.clear()}>C</Botao></td>
                        <td><Botao clique={()=>this.pressionar(0)}>0</Botao></td>
                        <td><Botao clique={()=>this.resultado()}>=</Botao></td>
                        <td><Botao clique={()=>this.soma()}>+</Botao></td>

                    </tr>
                </table>
            </div>
        )
    }
}

ReactDOM.render(<App />, document.getElementById("root"));

