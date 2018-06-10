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
		
	private: System::Windows::Forms::Timer^  timer1;
int n;
	private: System::Windows::Forms::Button^  button1;
			 CMazo^ mazo;
		
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			canvas = CreateGraphics();
			mazo = gcnew CMazo(canvas);
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(660, 164);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(129, 44);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Coger carta";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1018, 542);
			this->Controls->Add(this->button1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Uno el juego de cartas mas horrible de programar";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
		void dibujarfondo() {
			Bitmap^ bm_world = gcnew Bitmap("imagenes/esce.jpg");
			//bm_world->MakeTransparent(bm_world->GetPixel(1, 1));
			Drawing::Rectangle todaPantalla = Drawing::Rectangle(0, 0, 3100, 1300);
			canvas->DrawImage(bm_world, todaPantalla, 0, 0, this->Size.Width, this->Size.Height, GraphicsUnit::Pixel);
			//dibujar mario
		}
		void dibujar() {
			//dibujar fondo
			dibujarfondo();
			
			mazo->dibujarmazo();

		}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		dibujar();
			
		timer1->Stop();
		timer1->Enabled = false;
			
		mazo->cogercarta();
		timer1->Stop();
		
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		timer1->Enabled = true;
	}
};
}

