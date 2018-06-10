#pragma once
#include "CMazo.h"
#include "CJugador.h"
#include "CEscenario.h"
#include "CCarta.h"
#include "CJuego.h"

namespace Project15 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		Graphics^ canvas;
		BufferedGraphicsContext ^espacioBuffer;
		
	private: System::Windows::Forms::Timer^  timer1;
int n;


			 CMazo^ mazo;
		
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			canvas = CreateGraphics();
			espacioBuffer = BufferedGraphicsManager::Current;
			// Creamos un canvas dentro del espacio del buffer utilizando el canvas
			// del formulario
			BufferedGraphics ^buffer = espacioBuffer->Allocate(canvas, this->ClientRectangle);

			mazo = gcnew CMazo();
			n = 0;
			

			
			
		}
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1018, 542);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Uno el juego de cartas mas horrible de programar";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
		void dibujarfondo(BufferedGraphics ^buffer) {

			Bitmap^ bm_world = gcnew Bitmap("imagenes/esce.jpg");
			Drawing::Rectangle todaPantalla = Drawing::Rectangle(0, 0, 3100, 1300);
			buffer->Graphics->DrawImage(bm_world, todaPantalla, 0, 0, this->Size.Width, this->Size.Height, GraphicsUnit::Pixel);
			//bm_world->MakeTransparent(bm_world->GetPixel(1, 1));
		
		}
		
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		Graphics^g= CreateGraphics();
		BufferedGraphicsContext ^espacioBuffer = BufferedGraphicsManager::Current;
		BufferedGraphics ^buffer = espacioBuffer->Allocate(g, this->ClientRectangle);
		dibujarfondo(buffer);
		
		mazo->dibujarmazo(buffer);


		buffer->Render(g);
		delete buffer;
		delete espacioBuffer;  delete g;
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		//timer1->Enabled = true;
	}
};
}

